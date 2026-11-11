#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m;
ll ans=0,a[N];
void dfs(int dep,int cnt,ll sum)
{
	if(cnt==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(cnt==0)
	{
		for(int i=dep;i>=1;i--)
		{
			dfs(i-1,cnt+1,a[i]);
		}
	}
	for(int i=dep;i>=1;i--)
	{
		int sum1=sum&a[i];
		if(sum1>ans)
		{
			dfs(i-1,cnt+1,sum1);
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(n,0,0);
	printf("%lld",ans);
	return 0;
}
