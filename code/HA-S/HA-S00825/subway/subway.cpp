#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r,a[505][2005],b[500005],z[500005],s[500005];
void dfs(long long x,long long k)
{
	s[x]=min(k,s[x]);
	if(x==r)
	{
		return;
	}
	b[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i][x]!=0)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]!=0&&b[j]==0&&k+a[i][x]+a[i][j]<s[j])
					dfs(j,k+a[i][x]+a[i][j]);
			}
		}
	}
	b[x]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&z[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i][0]);
		for(int j=1;j<=a[i][0];j++)
		{
			scanf("%lld%lld",&l,&r);
			a[i][l]=r;
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&l,&r);
		for(int j=1;j<=m;j++)
		{
			s[j]=1e15;
		}
		dfs(l,0);
		printf("%lld\n",s[r]+z[l]+z[r]);
	}
	return 0;
}
