//GZ-S00005 ²ÜÓþèñ
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],cn=1,ans,d[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1; i<=n; i++)
	{
		cin >> a[i];
		if(i!=1 && a[i]-a[i-1]>m)
		{
			cn=i;
		} 
		d[i]=cn;
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<n; i++)
	{
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i]*i;
	}
	for(long long i=1; i<=n; i++)
	{
		if(c[i-1]<=m)
		{
		    ans=max(ans,i);
		}
		else
		{
			for(long long j=d[i]; j<i; j++)
			{
				if(i-j+1<ans)
				    break;
				if(c[i-1]-c[j-1]<=m)
				{
					ans=max(ans,i-j+1);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
