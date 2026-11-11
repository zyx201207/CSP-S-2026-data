#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans=INT_MAX,le;
long long d,a[2000005];
void dfs(int x,int y,int k)
{
	if(k>ans) return;
	if(x==y)
	{
		if(ans==k) le++;
		else
		{
			ans=min(ans,k);
			le=1;
		}
		return;
	}
	for(int i=y;i>x;i--)
	{
		if(a[i]-a[x]<=d)
		{
			dfs(i,y,k+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		int cnt=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=INT_MAX;
				le=1;
				dfs(i,j,0);
				if(le==2) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

