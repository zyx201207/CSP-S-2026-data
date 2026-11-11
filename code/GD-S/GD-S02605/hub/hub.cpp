#include<bits/stdc++.h>
using namespace std;
long long n,m,sum1,s,dp[1000005],cf[1000005],mx=1,su=1;
struct st
{
	long long ca,zh;
	long long cff;
}a[1000005];
bool cmp(st e,st r)
{
	return e.zh<r.zh;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].zh;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		if((a[i].zh-a[i-1].zh)*su+sum1<=m)
		{
			sum1+=(a[i].zh-a[i-1].zh)*su;
			su++;
		}
		else
		{
			for(int j=i-su;j<=i;j++)
			{	
				sum1-=a[i-1].zh-a[i-su].zh;
				su--;
				if((a[i].zh-a[i-1].zh)*su+sum1<=m)
				{
					sum1+=(a[i].zh-a[i-1].zh)*su;
					su++;
					break;
				}
			}
		}
		mx=max(mx,su);
	}
	cout<<mx; 
	return 0;
} 
