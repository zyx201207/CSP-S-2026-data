#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,f[N];
struct hh{
	int u,v;
}a[N];
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
		for(int i=1;i<=n-1;i++)
		{
			cin>>a[i].u>>a[i].v;
		}
		cout<<k-1<<"\n";
	}
	return 0;
}
