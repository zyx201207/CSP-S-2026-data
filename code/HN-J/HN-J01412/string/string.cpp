#include<bits/stdc++.h>
using namespace std;
int n;
string ans="0";
string s="";
void add();
void init();
void work();
void print();
void add(char &a,int b){
	char t=a;
	if(t=='9'){
		if(b==0){
			for(int i=0;i<ans.size();i++){
				swap(ans[i],ans[i+1]);
			}	
			ans[0]=1;
			ans[1]=0;
		}
		else add(ans[b-1],--b);
	}
	else a++;
}
void init(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a; char b;
		cin>>a;
		cin>>b;
		for(int j=0;j<a;j++) s+=b;
	}
}
void work(){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[n-i]){
			add(ans[ans.size()-1],ans.size()-1);
		}
	}
}
void print(){
	cout<<ans;
}
int main(){
	init();
	work();
	print();
	return 0;
} 
