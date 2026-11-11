#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5*1e5;
ll n,m,a[MAXN],c[10005],s,ans=-1,maxn=-1e12-1,minn=1e12+1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s+=a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(maxn-minn>=1e6)
	{
		for(int i=s/n-100;i<=s/n+100;i++)
		{
			for(int j=1;j<=n;j++)
			{
				 c[j]=abs(i-a[j]);
			}
			sort(c+1,c+n+1);
			int cnt=0,point;
			for(int j=1;true;j++)
			{
				cnt+=c[j];
				if(cnt==m)
				{
					point=j;
					break;
				}
				if(cnt>m)
				{
					point=j-1;
					break;
				}
			}
			ans=max(ans,1ll*point);
		}
		printf("%lld",ans);
		exit(0);
	}
	for(int i=minn;i<=maxn;i++)
	{
		for(int j=1;j<=n;j++)
		{
			 c[j]=abs(i-a[j]);
		}
		sort(c+1,c+n+1);
		int cnt=0,point;
		for(int j=1;true;j++)
		{
			cnt+=c[j];
			if(cnt==m)
			{
				point=j;
				break;
			}
			if(cnt>m)
			{
				point=j-1;
				break;
			}
		}
		ans=max(ans,1ll*point);
		if(point==n) break;
	}
	printf("%lld",ans);
	return 0;
}
