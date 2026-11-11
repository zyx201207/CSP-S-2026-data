#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
vector<int> g[N];
int n,k;
bool vis[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<=n;++i)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n) cout<<0<<'\n';
		else if(k>=(n+1)/2) cout<<1<<'\n';
		else if(k==1) cout<<((n+1)/2+1)/2<<'\n';
		else cout<<((n+1)/2-k)/2/2+1<<'\n';
	}
	return 0;
}

