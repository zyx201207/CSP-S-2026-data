#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int f=d/(x[2]-x[1]);
		if(n<(2*f-1)||f<=1)
		{
			cout<<0;
		}
		else
		{
			cout<<n-(2*f-1);
		}
		cout<<"\n";
	}
	return 0;
}
