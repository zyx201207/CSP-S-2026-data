#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long ans,w[500005],k[500005],a[505][505],t[505][505];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];	
		}
	}
	while(q--){
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==x)
				}
			}	
		}
	}
	return 0;
}
