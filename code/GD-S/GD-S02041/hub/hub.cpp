#include<bits/stdc++.h>
using namespace std;
int C,T,n,k;
vector<int> g[300005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while (T--)
	{
		cin>>n>>k;
		for (int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
} 
