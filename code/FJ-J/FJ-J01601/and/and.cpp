#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool f[200005];
long long ans=0;
int dfs(int n,int m,long long an)
{
	if(m==0)
	{
		//cout<<an<<' ';
		if(ans<an)
		{
			ans=an;
		}
		return an;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(n,m-1,(an&a[i]));
			f[i]=0;
		}
	}
	return an;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,0,sizeof(f));
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		f[i]=1;
		dfs(n,m-1,a[i]);
		f[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
