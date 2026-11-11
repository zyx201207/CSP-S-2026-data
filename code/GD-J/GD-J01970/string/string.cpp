#include<bits/stdc++.h>
using namespace std;
int f[200010],l,r,n;
long long ans=0,bj;
char dp[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i]>>dp[i];
	}
	while(l<=r)
	{
		if(l>=r)break;
		else
		{
			bj=min(f[l],f[r]);
			f[l]-=bj;
			f[r]-=bj;
			if(dp[l]!=dp[r])ans+=bj;
			if(f[l]==0)l++;
			if(f[r]==0)r--; 
		}
	}
	cout<<ans;
	return 0;
}
