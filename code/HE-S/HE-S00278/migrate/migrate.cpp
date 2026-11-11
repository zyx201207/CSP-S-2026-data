#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int c,T,n,d,ans;
int dp[N],x[N],sp[N];
deque<int> dq;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int tu=1;tu<=n;tu++)
		{
			while(!dq.empty())dq.pop_front();
			memset(dp,0,sizeof(dp));
			memset(sp,0,sizeof(sp));
			sp[tu]=1;
			for(int i=tu;i<=n;i++)
			{
				while(!dq.empty()&&x[i]-x[dq.front()]>d)
					dq.pop_front();		
				if(!dq.empty())dp[i]=dp[dq.front()]+1;
				for(int j=0;j<dq.size();j++)
				{
					if(j&&dp[dq[j]]!=dp[dq[j-1]])break;
					sp[i]+=sp[dq[j]];
				}
				if(sp[i]==2)ans++;
				dq.push_back(i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
