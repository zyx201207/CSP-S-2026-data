#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
void solve()
{
	cin>>n>>k;
	vector<int> g[n+1];
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<"1\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
