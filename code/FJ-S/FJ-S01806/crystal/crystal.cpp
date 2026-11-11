#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],ans=1,s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
	}
	for(long long i = 1;i<=n;i++)
	{
		long long cnt=1,e=0;
		for(long long j = i+1;j<=n;j++)
		{
			e+=s[j]*(j-i);
			if(e>m) break;
			cnt++;
		}
		ans=max(cnt,ans);
		if(ans>=n-i)
			break;
	}
	cout << ans;
	return 0;
} 
