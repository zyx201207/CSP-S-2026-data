#include<bits/stdc++.h>
using namespace std; 
int c,n,m,d,q,w[50010],G[20010][20010];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			G[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int t,a[50010],ti[50010];
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>a[j]>>ti[j];
			for(int k=1;k<j;k++){
				G[a[k]][a[j]]=ti[k]+ti[j];
				G[a[j]][a[k]]=ti[k]+ti[j];
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<setw(5)<<G[i][j]; 
//		}
//		cout<<"\n";
//	}
	for(int k=1;k<=m;k++){
		for(int u=1;u<=m;u++){
			for(int v=1;v<=m;v++){
				G[u][v]=min(G[u][v],G[u][k]+G[k][v]);
			}
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<G[st][ed]+w[st]+w[ed]<<"\n";
	}
	return 0;
}
