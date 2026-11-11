#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans;
ll s[500005],sum,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1,wh=1;i<=n;i++)
	{
		sum+=(s[i]-s[i-1])*(i-wh);
		while(sum>m&&wh<i)
		sum-=s[i]-s[wh],wh++;
		ans=max(ans,i-wh+1);
	}printf("%d",ans);
}
