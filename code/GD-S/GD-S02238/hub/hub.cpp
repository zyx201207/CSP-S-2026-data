#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,k,u,v;
		cin>>n>>k;
		vector<int> e[1000005];
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<n-k<<endl;
	}
	return 0;
}
