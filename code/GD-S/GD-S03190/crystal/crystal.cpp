#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],s[500100],dp[500100],w[500100],cnt=1,ans,maxn,ma,i,j=1,k=1;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	s[1]=1;dp[1]=1;ans=1;
	for(i=2;i<=n;i++)
	{
		ans=max(dp[i-1],ans);
		s[i]=s[i-1]+a[i];long long t=w[i-1]+(a[i]-a[i-1])*dp[i-1];
		if(t<=m){
			dp[i]=dp[i-1]+1;
			w[i]=t;
		}
		else
		{
			for(j=k;j<=i;j++)
			{
				t-=(a[i]-a[j]);
				if(j==i)
				{
					k=i;dp[i]=1;break;
				}
				if(t<=m)
				{
					dp[i]=i-j;
					k=j+1;
					w[i]=t;
					break;
				}
			}
		}
	}ans=max(dp[n],ans);
//	for(i=1;i<=n;i++)cout<<dp[i]<<" "<<w[i]<<endl;
	printf("%lld",ans);
	return 0;
}
