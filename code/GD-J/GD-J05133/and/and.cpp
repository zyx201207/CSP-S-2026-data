#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[200008],ans;
LL w[200008];
bool vis[200008];
void dfs(LL step)
{
	if (step>m)
	{
		LL last=w[1];
		for (int i=2;i<=m;i++)
		{
			last=last&w[i];
		}
		ans=max(ans,last);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			w[step]=a[i];
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
