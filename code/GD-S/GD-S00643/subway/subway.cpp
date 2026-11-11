#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN=5e5+100,MaxM=550;
const ll inf=1e18;

int c,n,m,d,q;
ll w[MaxN],f[MaxM][MaxM];
vector<pair<int,ll> > to[MaxN];

int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		while(k--){
			int a;
			ll t;
			cin>>a>>t;
			to[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(auto a:to[i]){
			for(auto b:to[i]){
				int u=a.first,v=b.first;
				ll w=a.second+b.second;
				if(u==v)continue;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for(auto a:to[x]){
			for(auto b:to[y]){
				ans=min(ans,f[a.first][b.first]+a.second+b.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	
	return 0;
} 
