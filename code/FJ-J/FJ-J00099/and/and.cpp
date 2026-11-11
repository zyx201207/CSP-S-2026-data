#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int a[35]={},n,b[25500],mx=0,m;
cin>>n>>m;int l=0,p=n;
for(int i=1;i<=n;i++){
	cin>>b[i];
	mx=max(mx,b[i]);
}
/*
for(int i=1;i<=p;i++){
	int l=log(b[i]);
	a[l]++;
}
for(int k=32;k>=0;k--){
if(k==0){
	cout<<0;
	return 0;}
if(a[k]>=m){
	p=k;
	break}}*/
	cout<<mx;
	return 0;
}
