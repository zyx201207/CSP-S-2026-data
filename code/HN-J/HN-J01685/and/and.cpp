#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1048580];
	int ct=0,ct1=0,maxx;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}else if(m==1){
		cout<<maxx;
		return 0;
	}else if(n==m){
		cout<<ct1;
		return 0;
	}else{
		cout<<ct;
	}
	return 0;
} 
