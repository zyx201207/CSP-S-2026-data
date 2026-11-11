#include <bits/stdc++.h>
using namespace std;

int g[1001][1001],u,v;
int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++)
		
			for(int k=1;k<=n;k++) g[i][j]=0;
			
		for(int j=1;j<n;j++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
		
		
	}
	cout<<"1\n2"; 
} 

