#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2123456];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		int x,y;
		cin>>x>>y;
		for (int j=1;j<=x;j++)
		{
			scanf("%lld",&a[j]);
		}
		cout<<x/(y*2)<<endl;
	}
	return 0;
}
