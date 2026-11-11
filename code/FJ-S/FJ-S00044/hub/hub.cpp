#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=15;
vector<ll> g[N];
ll bo[N];
vector<ll> g2[N]; 
ll vis[N];
ll res=0;
void dfs(ll u)
{
	if(vis[u]) return;
	vis[u]=res;
	for(int v:g2[u])
	{
		dfs(v);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>c>>T;
	while(T--)
	{
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int mask=0;mask<(1<<n);mask++)
		{
			memset(vis,0,sizeof(vis));
			memset(bo,0,sizeof(bo));
			ll cnt=0;
			for(int i=1;i<=n;i++)
			{
				g2[i].clear();
				if((mask>>i)&1)
				{
					bo[i]=1;
					cnt++;
				}
			}
			if(cnt<k) continue;
			for(int i=1;i<=n;i++)
			{
				for(int v:g[i])
				{
					if(bo[i]&&bo[j])
					{
						g2[i].push_back(j);
						g2[j].push_Back(i);
					}
				}
			}
			cout<<0<<'\n';
		}
	}
	return 0;
}
/*
n座城市和n-1条道路构成一棵树T。
择.恰.好k座城市，
，所有合理的建造方案的通勤半径的最小值


*/
