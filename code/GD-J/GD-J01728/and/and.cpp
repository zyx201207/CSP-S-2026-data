#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
int vis[N];
int n,m;
ll ans=0;
void dg(int x,ll res)
{
	if (x>m)
	{
		ans=max(ans,res);
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0)
		{
			vis[i]=1;
			dg(x+1,(res&a[i]));
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (n<=20)
	{
		dg(1,(1<<30)-1);
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",ans);
	return 0;
}
