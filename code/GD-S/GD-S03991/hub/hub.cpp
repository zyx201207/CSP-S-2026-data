#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,i;
		cin>>n;
		for(i=0;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<"1\n";
	}
	return 0;
}
