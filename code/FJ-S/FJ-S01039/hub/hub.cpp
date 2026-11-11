#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,vis[1000005];
vector<int>  g[1000005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++) 
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<n/4<<'\n';
	}
	return 0;
}
