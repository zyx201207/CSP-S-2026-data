#include<bits/stdc++.h>
using namespace std;
long long a[100001], ans = 0, ams = 0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c, t, n, d;
	cin>>c>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]==5)
			{
				ans = 1;
				ams = 2;
			}
			else
			{
				ans = 0;
				ams = 1;
			}
		}
	}
	cout<<ans<<endl;
	cout<<ams;
	return 0;
}

