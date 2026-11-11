#include<bits/stdc++.h>
using namespace std;
long long c,t,d[1000005],n,k,u,v;
vector<long long> e[1000005];
void dfs(long long u,long long fa)
{
	for (long long v : e[u])
	{
		if (v != fa)
		{
			d[v] = d[u] + 1;
			dfs(v,u);
		}
	}
}
int main()
{
	// ¿ì¶Á 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// Ö÷´úÂë
	cin>>c>>t;
	for (long long i = 1;i <= t;i++)
	{
		for (long long i = 1;i <= n;i++) e[i].clear();
		cin>>n>>k;
		for (long long i = 1;i <= n - 1;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<i<<'\n'; 
	}
	return 0;
}
