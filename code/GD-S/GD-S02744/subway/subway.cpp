#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int w[M],k,z,a,b,a1,b1;
int c,n,m,d,q;
int s,e;
int cost[1005][1005];
vector<int>y[M];
bool vis[1005];
int mi=1e18;
void dfs(int u,int sum){
	if(sum>=mi) return ;
	if(u==e){
		mi=min(sum,mi);
		return ;
	}
	for(int i=0;i<y[u].size();i++)
		if(!vis[y[u][i]]){
			vis[y[u][i]]=1;
			dfs(y[u][i],cost[u][y[u][i]]+sum);
			vis[y[u][i]]=0;
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k==1) continue;
		cin>>a>>a1>>b>>b1;
		y[a].push_back(b),y[b].push_back(a);
		cost[a][b]=min(cost[a][b],a1+b1),
		cost[b][a]=min(cost[b][a],a1+b1);
	}
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		mi=1e18;
		cin>>s>>e;
		dfs(s,w[s]+w[e]);
		cout<<mi<<'\n';
	}
	return 0;
}

