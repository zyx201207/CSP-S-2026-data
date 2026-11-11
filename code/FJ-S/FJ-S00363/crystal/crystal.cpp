#include <bits/stdc++.h>
using namespace std;
const long long N=1e5*5+10;
//¸Älong long!!! 
long long n,m;
long long ans=0;
long long a[N];
long long sum[N];
bool vis[N];
long long mid,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(vis,false,sizeof(vis));
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cnt+=a[i];
	}
	sort(a+1,a+1+n);
	long long jl=0,minn=INT_MAX;
	mid=cnt/n;
	//printf("%d\n",mid);
	for(long long i=1;i<=n;i++)
	{
		sum[i]=abs(mid-a[i]);
		//printf("%d ",sum[i]);
	}
	//printf("\n");
	long long cntt=0;
	while(cntt<=m)
	{
		minn=INT_MAX;
		for(long long i=1;i<=n;i++)
		{
			if(minn>sum[i] && !vis[i])
			{
				minn=sum[i];
				jl=i;
			}
			if(minn==0)
			{
				jl=i;
				break;
			}
		}
		//printf("%d\n",jl);
		vis[jl]=true;
		if(cntt+sum[jl]>m)		break;
		cntt+=sum[jl];
		ans++;
//		printf("%d\n",cntt);
//		for(long long j=1;j<=n;j++)
//		{
//			printf("%d ",vis[j]);
//		}
//		printf("\n");
	}
	printf("%lld",ans);
	return 0;
}
