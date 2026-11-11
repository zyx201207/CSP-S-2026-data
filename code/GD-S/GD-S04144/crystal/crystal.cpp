#include<bits/stdc++.h>
using namespace std;
long long a[500100],b[500100];
long long cnt=1,maxa=INT_MIN;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			b[i]=a[i]-a[i-1];
		}
		else
		{
			b[i]=a[i-1]-a[i];
		}
	}
	long long sum=m;
	for(long long i=2;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(sum>=b[j])
			{
				sum-=b[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		if(cnt>maxa)
		{
			maxa=cnt;
		}
		sum=m;
		cnt=0;
	}
	cout<<maxa;
	return 0;
}
