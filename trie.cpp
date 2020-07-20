#include <bits/stdc++.h>
using namespace std;

struct node{
	map<char,node*>children;
	bool isWord;
};

void insert(struct node* &root, string str){		
		struct node* crawl = root;		
		for(int i=0; i<str.length();i++){
			if(crawl->children.find(str.at(i)) == crawl->children.end()){
				crawl->children[str.at(i)] = new node;
			}				
			crawl = crawl->children[str.at(i)];
		}
		crawl->isWord = true;
}

bool search(struct node* &root, string str){
	
	struct node* crawl = root;
	for(int i=0; i<str.length(); i++){
		if(crawl->children.find(str[i]) ==  crawl->children.end()){
			return false;
		}
		crawl = crawl->children[str[i]];
	}
	return true;
}

void traverse(struct node* root, string res){
		map<char,node*>::iterator itr;
		if(root->isWord){
		  cout<<res<<endl;
		}
		for(itr = root->children.begin(); itr!=root->children.end(); ++itr){			
			res.push_back(itr->first);
			traverse(itr->second,res);
			res.pop_back();
		}
}
void printAll(struct node* root, string patt){
	struct node* crawl = root;
	for(int i=0; i<patt.length(); i++){
		if(crawl->children.find(patt[i]) ==  crawl->children.end()){
			return ;
		}
		crawl = crawl->children[patt[i]];
	}
	string res;
	traverse(crawl,res+patt);
}

int main(){
	
	struct node* root = new node;
	//build trie
	insert(root , "lady");
	insert(root,"lazy");
	insert(root,"lizard");
	insert(root,"crazy");
	insert(root,"dazy");
	insert(root,"cry");
	
	//check for the existence of the strings
	cout<<"dazy "<<search(root,"dazy")<<endl;
	cout<<"lazy "<<search(root,"lazy")<<endl;
	cout<<"zazy "<<search(root,"zazy")<<endl;
	
	//Print all strings with prefix "la"
	printAll(root,"la");
	
	return 0;
}
