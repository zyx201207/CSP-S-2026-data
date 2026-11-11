#include<bits/stdc++.h>
using namespace std;
int a[541141];
int d[514514];
#define int long long
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxn=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		memset(d,0,sizeof(d));
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((a[i]-a[j])>=0) d[++cnt]=a[i]-a[j];
			else break;
		}
		sort(d+1,d+cnt+1);
		int sum=0;
		for(int j=1;j<=cnt;j++)
		{
			sum+=d[j];
			if(sum>m)
			{
				ans=j;
				break;
			}
		}
		if(sum<m) ans=cnt;
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
//CCF,YOU IS AN BETTER PEOPLES.(I CAN'T SAY CORRECT SENTENCE BECAUSE I AM ANGRY!)
