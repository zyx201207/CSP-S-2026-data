#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int a=1;a<=t;a++){
		int n,k,f=0;
		cin>>n>>k;
		int u[100000],g[100000];
		for(int i=1;i<=n;i++){
			cin>>u[i]>>g[i];
			f=max(f,abs(u[i]-g[i]));
		}
		cout<<f<<endl; 
	}
	return 0;
}
