#include<bits/stdc++.h>
using namespace std;
const int N=2000005,INF=0x3f3f3f;
int a[N],dp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--)
	{
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			memset(dp,sizeof(dp),INF);
			dp[i]=0;
			for(int j=i+1;j<=n;j++)//假设i,j是 
			{
				if(a[j]-a[j-1]>d)break;
				int tmp=0;
				for(int k=j-1;k>=1;k--)//找上一步的岛屿 
				{
					if(a[j]-a[k]>d)break;
					if(dp[k]+1<dp[j])
					{
						dp[j]=dp[k]+1;
						tmp=0;
					}
					else if(dp[k]+1==dp[j])
					{
						if(tmp==0)tmp=1;
						else
						{
							tmp=0;
							break;
						}
					}
				}
				if(tmp==1)
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
