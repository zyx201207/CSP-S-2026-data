#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=500+5;
const int M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,x,y;
int w[M],k[N];
vector<vector<int>>a;
vector<vector<ll>>t;
vector<pair<int,ll>>g[N+M];
ll dis[N][N];
void Main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	a.assign(n+1,vector<int>());
	t.assign(n+1,vector<ll>());
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].assign(k[i]+1,0);
		t[i].assign(k[i]+1,0ll);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i+m,t[i][j]});
			g[i+m].push_back({a[i][j],t[i][j]});
		}
	}
	for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len-1;j++){
			for(int o=j+1;o<len;o++){
				int u=g[i][j].first-m,v=g[i][o].first-m;
				dis[u][v]=min(dis[u][v],g[i][j].second+g[i][o].second);
				dis[v][u]=min(dis[v][u],g[i][j].second+g[i][o].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				dis[i][j]=min(dis[i][j],dis[i][o]+dis[o][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	while(q--){
		cin>>x>>y;
		int l1=g[x].size();
		int l2=g[y].size();
		ll ans=inf;
		for(int i=0;i<l1;i++){
			for(int j=0;j<l2;j++){
				int u=g[x][i].first-m,v=g[y][j].first-m;
				ans=min(ans,g[x][i].second+g[y][j].second+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	FZT::Main();
	return 0;
}
