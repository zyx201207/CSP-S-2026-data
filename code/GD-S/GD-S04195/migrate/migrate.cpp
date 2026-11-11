#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+5;
ll c,t,n,d,a[MAXN],dp[305],len[305],minn,ans;	//len[j]:长度最短的路径多长 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			memset(len,0,sizeof(len));
			dp[i]=1;
			for(int j=i+1;j<=n;j++){
				ll p=j-1,s=0; minn=1e18;
				while(p>=i&&a[j]-a[p]<=d){
					len[j]=len[p]+1;
					if(len[j]<minn){
						minn=len[j];
						dp[j]=dp[p];
					}
					else if(len[j]==minn) dp[j]+=dp[p];
					p--;
				}
				len[j]=minn;
				if(dp[j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
