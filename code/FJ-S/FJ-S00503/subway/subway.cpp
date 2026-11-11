/*
CSP-J&CSP-S2026游记
	1st CSP-J
2026年10月31日 晴 
  
*/
#include<bits/stdc++.h>
using namespace std;
int m,n,c,w[5005],k[5005],a[5005][5005];
int t[5005][5005],q,x,y,d;
bool b[5005][5005];
dfs(int x,int y)
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
	}
}
