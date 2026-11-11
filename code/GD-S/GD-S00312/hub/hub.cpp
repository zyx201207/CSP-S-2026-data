#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,k,h[55];
struct node
{
	int u,v;
};
vector<int> a[55];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	return 0;
}
