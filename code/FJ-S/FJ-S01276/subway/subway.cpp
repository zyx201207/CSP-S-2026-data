#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	int c,n,m,d,q,K2;
	long long w[m+1],t[K+1],j3[m+1][n];
	int qu[2*q+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int K[n+1][m+1],j1=0,j2[n];
	for(int j=1;j<=n;j++){
		cin>>K[j][0];
	    for(int i=1;i<=K[j][0];i++){
		    cin>>K[j][i]>>t[i];
		    if(j1==K[i][j])
		    j1=K[j][i];
	    }
	for(int i=1;i<=q;i=i+2){
		cin>>qu[i]>>qu[i+1];
	}
	long long tans=0;
	int e=q,m2[m][n];
	for(int i=1;i<=m;i++){
		if(!=1){
			
		}
	}
	while(e--){
		r=q-e;
		tans=w[qu[r]]+w[qu[r+1]];
		
	}
	return 0;
}
