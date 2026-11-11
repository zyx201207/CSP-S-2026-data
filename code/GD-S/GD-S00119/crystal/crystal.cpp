#include <bits/stdc++.h>
using namespace std;
long long a[50005],f[50005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long m1=m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		f[i]=a[i]-a[i-1];
	}
	long long ans=1,maxx=1;
	int b=1;
	for (int i=2;i<=n;i++)
	{
		if (b==1) m-=f[i];
		if (i!=2) f[i]/=2;
		b=1;
		if (m>=0)
		{
			if (f[i+1]==0) b=0;
			f[i+1]*=i;
			ans++;
			
		}
		else
		{
			m=m1;
			f[i]/=(i-1);
			i--;
			maxx=max(ans,maxx);
			ans=1;
		}
	}
	maxx=max(ans,maxx);
	cout<<maxx;
	return 0;
}
