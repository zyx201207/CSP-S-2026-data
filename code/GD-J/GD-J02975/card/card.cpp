#include<cstdio>
#include<cstring>
const long long N = 5e5+10;
long long dp[N],nums[N];
long long last[N];
long long jh[N],cnt[N],n,m;
bool vis[N];
void bl(int s)
{
	int ct = 0;
	for(int i = s;i<=n;i = jh[i])
	{
		ct+=(!vis[i]);
		if(nums[i] != nums[jh[i]])
		{
			cnt[nums[i]] += ct;
		}
		vis[i] = 1;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&nums[i]);
	}
	if(n*m<=(1e7))
	{
		for(long long i=1;i<=m;i++)
		{
			long long cnt = 0;
			for(long long j=n;j;j--)
			{
				dp[j] = 0;
				if(!last[nums[j]])
				{
					if(nums[j] == i) dp[j] = 1;
					dp[j] |= dp[j+1];
					last[nums[j]] = j;
				}
				else
				{
					if(nums[j] == i) dp[j] = 1;
					dp[j] |= dp[last[nums[j]]];
					last[nums[j]] = j;
				}
				if(dp[j]) cnt++;
			}
			printf("%lld ",cnt);
			memset(last,0,sizeof(last));
		}
		return 0;
	}
	else
	{
		for(long long j=n;j;j--)
		{
			if(!last[nums[j]])
			{
				jh[j] = j+1;
				last[nums[j]] = j;
			}
			else
			{
				jh[j] = last[nums[j]];
				last[nums[j]] = j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				bl(i);
			}
		}
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",cnt[i]);
		}
		return 0;
	}
	return 0;
}
