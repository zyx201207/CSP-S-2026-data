#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<vector<int>> g;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		g.assign(n+1,{});
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<n<<"\n";
	}
	return 0;	
} 
