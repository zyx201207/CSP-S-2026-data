#include<bits/stdc++.h>
using namespace std;
long long n,m,l,k,ct=0,x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=m;i++){
	cin>>x>>y;
	ct=0;
	cin>>k;
	for(int i=2;i<=x;i++){
		cin>>l;
		if(l-k>y)ct++;
	}
	cout<<ct<<endl;
} 
	return 0;
} 
