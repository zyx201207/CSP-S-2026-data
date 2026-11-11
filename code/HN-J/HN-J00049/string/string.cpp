#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n,m,cnt;
	string s,ls="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s;
		for(int j=1;j<=m;j++){
			ls+=s;
		}
	}
	int ix;
	ix=ls.size()-1;
	for(int i=0;i<ix/2;i++){

		if(ls[i]!=ls[ix-i]){
			cnt++;

		}
	}
	cout<<cnt;
	return 0;
}
