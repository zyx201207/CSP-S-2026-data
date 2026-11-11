//GZ-S00014 文泓浩 都匀市第三中学
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50000],b[50000],c[50000],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(a<=5000)
	{
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		for(int i=1; i<=n; i++)
		{
			b[i]=(i-1)*a[i];
			c[i]=a[i]+c[i-1];
		}
		for(int i=1; i<=n; i++)
		{
			if(b[i]-c[i-1]<=m) ans=i;
			else{
				break;
			}
		}
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
		}
		int p=a[2]-a[1];
		for(int i=1; i<=n; i++)
		{
			if(n<=sqrt(2*m/p+0.25)-0.5) ans=i;
			else{
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
