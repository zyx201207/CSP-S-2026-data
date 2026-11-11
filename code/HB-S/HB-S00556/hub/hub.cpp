#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
vector <long long> mapp[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(long long i=1;i<=n;i++)
		{
			mapp[i].clear();
		}
		for(long long i=1;i<n;i++)
		{
			long long u,v;
			cin>>u>>v;
			mapp[u].push_back(v);
			mapp[v].push_back(u);
		}
		cout<<(k+1)/2<<endl;
	}
	return 0;
}
