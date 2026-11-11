#include <bits/stdc++.h>

using namespace std;

#define int long long
int n,k,dep[2000005],maxx;
vector<int> edge[2000005];
void dfs (int u,int fa)
{
	dep[u]=dep[fa]+1;
	maxx=max(maxx,dep[u]);
	for (int v:edge[u])
	{
		if (v==fa)
			continue;
			
		dfs (v,u);
	}
}
signed main ()
{
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int c,T;
	cin >> c >> T ;
	
	while (T--)
	{
		cin >> n >> k ;
		
		if (k!=2)
		{
			cout << 0 ;
			continue;
		}
		
		for (int i=1;i<n;++i)
		{
			int u,v;
			cin >> u >> v ;
			
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		maxx=0;
		dfs (1,0);
		
		cout << maxx << '\n' ;
	}
	
	return 0;
}
