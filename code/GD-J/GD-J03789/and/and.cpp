#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000009],vis[1000009],cnt,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		vis[i]=1;
	}
	for(int i=29;i>=0;--i)
	{
		cnt=0;
		for(int j=1;j<=n;++j)
		{
			if(vis[j]&&(a[j]&(1<<i)))
			{
				++cnt;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;++j)
			{
				if((a[j]&(1<<i))==0)vis[j]=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
