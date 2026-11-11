#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[1000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<n-m-1<<'\n';
	}
	return 0;
}
