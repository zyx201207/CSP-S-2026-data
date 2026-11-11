#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m,a[200005],ans;
bool vis[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	if(n==m)
	{
		ans=a[1];
		for(ll i=2;i<=n;++i)
		{
			ans=ans&a[i];
		}
		return printf("%lld",ans),0;
	}
	int maxx=-1,vis1=-1,vis2=-1;
	for(int i=1;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(((a[i]&a[j])>maxx))
			{
				maxx=a[i]&a[j];
				vis1=i;
				vis2=j;
			}
		}
	}
	ans=maxx;
	vis[vis1]=true;
	vis[vis2]=true;
	if(m==2)
	{
		return printf("%lld",ans),0;
	}
	for(int z=1;z<=m-2;++z)
	{
		int minn=-1,visd=-1;
		for(int j=1;j<=n;++j)
		{
			if((!vis[j])&&((ans&a[j])>minn))
			{
				minn=ans&a[j];
				visd=j;
			}
		}
		ans=minn;
		vis[visd]=true;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

