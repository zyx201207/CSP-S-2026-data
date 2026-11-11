#include<bits/stdc++.h>
using namespace std;
int const N=2000005;
long long s[N],d,c,T,n,sum;
int v[N];
int l(int x,int y)
{
	int l=x,r=x,ans=1;
	while(r<=y)
	{
		if(s[r]-s[l]<=d)
		{
			r++;
		}
		else
		{
			ans++;
			r--;
			l=r;
		}
	}
	return ans;
}
void dfs(int x,int p,int a,int b)
{
	if(x==b&&p==l(a,b)) sum++;
	for(int i=x+1;i<=b;i++)
	{
		if(s[i]-s[x]<=d) return dfs(i,p+1,a,b);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		int tot=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum=0;
				dfs(i,0,i,j);
				if(sum==2) tot++;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
