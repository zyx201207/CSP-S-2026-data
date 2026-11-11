#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=6e5+5;
vector<pair<int,int> >zhan[maxn];
int dis[505][505];
int w[maxn];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		for(int j=1;j<=t;j++){
			int v,di;cin>>v>>di;
			zhan[v].push_back({i,di});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<zhan[i].size();j++){
			for(int k=0;k<zhan[i].size();k++){
				if(j==k)continue;
				int u=zhan[i][j].first,v=zhan[i][k].first;
				int w1=zhan[i][j].second,w2=zhan[i][k].second;
				dis[u][v]=min(dis[u][v],w1+w2);

			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){dis[i][j]=0;continue;}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int ans=1e18;
		int x,y;cin>>x>>y;
		for(int j=0;j<zhan[x].size();j++){
			for(int k=0;k<zhan[y].size();k++){
				int u=zhan[x][j].first,v=zhan[y][k].first;
				int w1=zhan[x][j].second,w2=zhan[y][k].second;
				ans=min(ans,w1+w2+dis[u][v]);
			}
		}ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
