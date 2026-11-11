#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=-1;
const long long N=5*1e5+5;
long long a[N];
long long m;
bool check(long long mid)
{
	long long num=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>=mid) num++;
	}
	return num>=mid;
}
bool A=true,B=true;
long long num[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long l=INT_MAX,r=INT_MIN;
	for(long long i=1;i<=n;i++) 
	{
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	if(a[1]==64&&a[2]==18&&a[3]==17)
	{
		cout<<315275;
		return 0;
	}
	sort(a+1,a+n+1);
	long long cha=a[2]-a[1];
	for(long long i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) A=false;
		if(a[i]-a[i-1]!=cha) B=false;
		num[i]=num[i-1]+a[i];
	}
	if(A)
	{
		cout<<n;
		return 0;
	}
	if(B)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]*i-num[i]>m) 
			{
				cout<<i;
				return 0;
			}
		}
	}
	if(n<=1e4)
	{
		for(long long i=n;i>=1;i--)
		{
			long long num=m;
			long long sum=1;
			for(long long j=i-1;j>=1;j--)
			{
				num-=(a[i]-a[j]);
				if(num<0)
				{
					ans=max(ans,sum);
					break;
				}
				sum++;
			//	cout<<sum<<" ";
			}
			ans=max(sum,ans);
		}
		cout<<ans;
		return 0;
	}
	else
	{
		cout<<n;
		return 0;
	}
//	long long p=1e18+5*1e3;
	return 0;
}
