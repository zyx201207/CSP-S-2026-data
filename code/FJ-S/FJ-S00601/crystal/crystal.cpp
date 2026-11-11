#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int n;
long long m;
long long a[MAXN];
int check(int x)
{
	long long cnt=0;
	for(int i=1;i<x;i++)
	{
		long long cha=a[x]-a[i];
		cnt+=cha;
		if(cnt>m) return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			long long sum=0;
			for(int j=i-1;j>=1;j--)
			{
				sum+=a[i]-a[j];
				if(sum<=m) cnt=max(cnt,i-j+1);
				else break;
			}
		}
		cout<<cnt;
	}
	else
	{
		int l=1,r=n;
		int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)==1)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans;
	}
	return 0;
}
 
