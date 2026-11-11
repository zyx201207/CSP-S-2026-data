#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000010];

int main()
{
	//please give me AC
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,u,v;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<(k+1)/2<<'\n';
	}
	return 0;
}
