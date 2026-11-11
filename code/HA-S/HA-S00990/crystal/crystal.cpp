#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1,cnt1,cnt2;
long long a[500005];
long long check(long long x,long long y)
{
	long long sum=0;
	for(long long i=x;i<y;i++)
	{
		sum+=a[y]-a[i];
	}
	if(sum>m)
	{
		return 0;
	}
	else
	{
		return y-x+1;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==i+1)
		{
			cnt1++;
		}
	}
	sort(a,a+n);
	if(cnt1==n)
	{
		long long nm=0;
		for(long long i=1;i<n;i++)
		{
			nm+=i;
			if(nm<=m)
			{
				ans=max(ans,i+1);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	long long ds=a[1]-a[0];
	for(long long i=1;i<n;i++)
	{
		if(a[i]-a[i-1]==ds)
		{
			cnt2++;
		}
	}
	if(cnt2==n-1)
	{
		long long nm=m;
		long long j=1;
		while(nm>=ds*j&&j<n)
		{
			nm-=ds*j;
			j++;
			ans=max(ans,j);
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(long long i=0;i<n;i++)
	{
		long long last;
		for(long long j=i+1;j<n;j++)
		{
			last=check(i,j);
			ans=max(ans,last);
			if(last==0)
			{
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
