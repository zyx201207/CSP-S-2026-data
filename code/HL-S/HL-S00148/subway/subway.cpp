#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,w[500010],ans,c,d,q,k,a[500050],t[500050];
int g[4050][4050];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)g[i][j]=0;
			g[i][j]=9999999999;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int s=1;s<=j;s++){
				if(a[s]==a[j])g[a[s]][a[j]]=g[a[j]][a[s]]=0;
				g[a[s]][a[j]]=min(g[a[s]][a[j]],t[j]+t[s]);
				g[a[j]][a[s]]=g[a[s]][a[j]];

			}
			
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(g[i][k]!=9999999999&&g[k][j]!=9999999999){
					if(g[i][k]+g[k][j]<g[i][j]){
						g[i][j]=g[i][k]+g[k][j];
					}
				}
			}
		}
	}
	while(q--){
		int x,y=0;
		cin>>x>>y;
		cout<<w[x]+w[y]+g[x][y]<<"\n";
	}
	
	return 0;
	
}
