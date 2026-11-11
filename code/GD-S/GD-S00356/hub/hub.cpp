#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
int c,t,n,k;
vector<int> edge[110];
int fa[110],siz[110];
int dist[110][110];
int get(int x) {return fa[x] == x?x:get(fa[x]);}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		memset(dist,0x3f,sizeof dist);
		for(int i = 0;i<n-1;i++)
		{
			int u,v;cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			dist[u][v] = dist[v][u] = 1;
		}
		for(int i = 1;i<=n;i++) dist[i][i] = 1;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				for(int k = 1;k<=n;k++)
				{
					dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
				}
			}
		}
		int min_ans = INF;
		for(int i = 0;i<(1 << n);i++)
		{
			for(int j = 1;j<=n;j++) {fa[j] = j;siz[j] = 1;}
			int cnt = 0;
			vector<int> pot;
			for(int j = 0;j<n;j++)
			{
				if(((i >> j) & 1) == 0) continue;
				pot.push_back(j + 1);
				cnt++;
				int u = j + 1;
				for(int v:edge[u])
				{
					if((i >> (v-1)) & 1) 
					{
						int a = get(u),b = get(v);
						if(a ==b )continue;
						if(siz[a] < siz[b]) swap(a,b);
						fa[b] = a;
						siz[a] += siz[b];
					}
				}
			}
			if(cnt != k) continue;
			cnt = 0;
			for(int i = 1;i<=n;i++) {
				get(i);
				if(fa[i] == i){
					cnt++;
				}
			}
			if(cnt != n - k + 2) continue;
			int ans = 0;
			for(int j = 1;j<=n;j++)
			{
				for(int k:pot) ans = max(dist[j][k],ans);
			}
			min_ans = min(ans,min_ans);
		}
		cout << min_ans << '\n';
	}
	return 0;
 } 
