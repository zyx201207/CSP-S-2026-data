#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
long long n,m;
bool check(long long mid)
{
	for(long long i = mid ; i <= n ; i++)
	{
		if(a[i]*mid-(pre[i]-pre[i-mid])<=m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i = 1 ; i <= n ; i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	long long l=1,r=n;
	long long mid=1;
	mid=(l+r)/2;
	while(l<=r)
	{
		if(check(mid))
		{
			//cout << "当mid为" << mid << "时可以，继续尝试" << mid+1 << "到" << r << "范围" << endl; 
			l=mid+1;
		}
		else
		{
			//cout << "当mid为" << mid << "时不可以，继续尝试" << l << "到" << mid-1 << "范围" << endl; 
			r=mid-1;
		}
		mid=(l+r)/2;
	}
	long long ans=mid;
	for(long long i = mid ; i <= n ; i++)
	{
		if(a[i]*mid-(pre[i]-pre[i-mid])<=m)
		{
			long long mx=mid;
			for(long long j = i+1 ; j<=n ; j++)
			{
				if(a[j]==a[i])
				{
					mx++;
				}
				else
				{
					ans=max(mx,ans);
					break;
				}
			}
		}
	}
	cout << ans;
	/*
	long long ans=-1;
	for(long long i = 1 ; i <= n ; i++)
	{
		int temp=0;
		if(a[i]*i-pre[i]<=m) temp=i;
		int l=i-1;
		while(l>=1)
		{
			if(a[i]*(i-l)pre[i]-pre[l])
		}
		ans=max(temp,ans);
	}
	cout << ans;
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
