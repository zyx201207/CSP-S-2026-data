#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const long long N = 5e5+10;
long long nums[N];
long long sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",nums+i);
	}
	sort(nums+1,nums+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum[i]+=sum[i-1]+nums[i];
	}
	long long ans = 1;
	for(long long i=2,s = 1;i<=n;i++)
	{
		long long nd = (i-s)*nums[i]-(sum[i-1]-sum[s-1]);
		while(nd>m&&s<i)
		{
			s++;
			nd = (i-s)*nums[i]-(sum[i-1]-sum[s-1]);
			//printf("nd:%lld\n",nd);
		}
		ans = ans>(i-s+1)?ans:(i-s+1);
		//printf("nn:%lld   %lld %lld\n",i-s+1,i,s);
	}
	printf("%lld",ans);
	return 0;
}
