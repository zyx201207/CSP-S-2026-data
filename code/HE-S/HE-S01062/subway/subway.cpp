#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,num=0;
int a[10001];
int g[10001][10001],t[10001][10001],k[10001],q1[10001][3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>g[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>q1[i][0]>>q1[i][1];
	}
	for(int i=1;i<=q;i++){
		num=num+a[q1[i][0]]+a[q1[i][1]];
		
	}
	cout<<num;
	return 0;
}
