#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k;
vector<int> lu[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			lu[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			lu[u].push_back(v);
			lu[v].push_back(u);
		}
		
	}
	return 0;
 } 
