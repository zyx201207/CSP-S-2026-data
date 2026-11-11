#include<bits/stdc++.h>
using namespace std;	
int n,m,a[200005],book[200005],c[200005];
long long maxn=INT_MIN;
void dfs(int x)
{
	if(x==m+1)
	{
		long long ans=a[c[1]];
		for(int i=2;i<=m;i++)
		{
			long long t=a[c[i]];
			ans=ans&t;
		}
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0&&i>c[x-1])
		{
			c[x]=i;
			dfs(x+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	printf("%lld",maxn);
	return 0;
}
