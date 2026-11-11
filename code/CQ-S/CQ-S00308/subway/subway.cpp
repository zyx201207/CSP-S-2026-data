#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
ll val[N];
ll dis[505][505];
pair<int,int>h[N][25];
int l[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>val[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			h[a][++l[a]]=make_pair(i,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=l[i];j++){
			for(int k=j+1;k<=l[i];k++){
				int u=h[i][j].first,v=h[i][k].first;ll w=h[i][j].second+h[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){int u,v;cin>>u>>v;ll ans=val[u]+val[v];
		ll res=inf;
		for(int i=1;i<=l[u];i++){
			for(int j=1;j<=l[v];j++){
				int a=h[u][i].first,b=h[v][j].first,w=h[u][i].second+h[v][j].second;
				res=min(res,dis[a][b]+w);
			}
		}
		cout<<ans+res<<"\n";
	}
	return 0;
}
