#include<bits/stdc++.h>
using namespace std;
bool hw(string x){
	string s;
	for(int i=0;i<x.size();i++){
		s[i]=x[x.size()-i-1];
	}
	if(s==x){
		return true;
	}
	return false;
}
int n;
struct node{
	int num;
	char letter;
}a[200010]={};
int many(string s,string w){
	int sum=0;
	for(int i=0;i<w.size();i++){
		if(s[i]!=w[i]){
			sum++;
		}
	}
	return sum;
}
int choose(string s){
	int mid=s.size()/2;
	string w1,w2;
	for(int i=0;i<=mid;i++){
		w1[i]=s[i];
		w2[i]=s[s.size()-1-i];
	}
	for(int i=mid;i<s.size();i++){
		w2[i]=s[i];
		w1[i]=s[s.size()-1-i];
	}
	return min(many(s,w1),many(s,w2));
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s={};
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].letter;
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].letter;
		}
	}
	if(hw(s)){
		cout<<0;
	}else{
		cout<<choose(s);
	}
	return 0;
}
