#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int>e[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
	}
	return 0;
}
