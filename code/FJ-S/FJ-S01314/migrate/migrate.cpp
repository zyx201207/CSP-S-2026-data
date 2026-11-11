#include<bits/stdc++.h>
using namespace std;
long long a[500050],w[500050],t,ans=0,c,m,n,d,q,k[500050],x[1005],y[1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>x[i]>>y[i];
		for(int j=0;j<x[i];j++)cin>>a[i];
	}
	for(int i=1;i<=t;i++){
		cout<<x[i];
	}
}
