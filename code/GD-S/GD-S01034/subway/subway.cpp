#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxm=5e5+50,maxn=505,INF=1e18;
struct Node{
	ll id,val;
};
vector<Node>G[maxm];
ll c_id,n,m,d,q,w[maxm];
ll dis[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll u,w;
			cin>>u>>w;
			G[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;	
	}
	for(int i=1;i<=m;i++){
		if(G[i].empty()) continue;
		for(int j=0;j<(int)G[i].size();j++){
			for(int k=j+1;k<(int)G[i].size();k++){
				dis[G[i][j].id][G[i][k].id]=min(dis[G[i][j].id][G[i][k].id],G[i][j].val+G[i][k].val);
				dis[G[i][k].id][G[i][j].id]=min(dis[G[i][k].id][G[i][j].id],G[i][j].val+G[i][k].val);
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
	for(int i=1,s,t;i<=q;i++){
		cin>>s>>t;
		ll res=INF;
		for(int j=0;j<(int)G[s].size();j++){
			for(int k=0;k<(int)G[t].size();k++){
				res=min(res,w[s]+w[t]+G[s][j].val+G[t][k].val+dis[G[s][j].id][G[t][k].id]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
