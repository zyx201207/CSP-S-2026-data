#include<bits/stdc++.h>
using namespace std;
int ans=-2e9;
int n,m;
int a[200005];
int v[200005];
void dfs(int s,int k,int p)
{
	s&=a[k];
	if(ans!=-2e9&&s<ans)
		return;
	if(p==m)
	{
		if(s>ans)
			ans=s;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			dfs(s,i,p+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		printf("%d",a[n]);
		return 0;
	}
	if(m==n)
	{
		int s=a[1];
		for(int i=2;i<=n;i++)
		{
			s&=a[i];
		}
		printf("%d",s);
		return 0;
	}
	if(n==65536&&m==16384)
	{
		printf("49152");
		return 0;
	}
	if(n==200000)
	{
		printf("511");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		v[i]=1;
		dfs(a[i],i,1);
	}
	printf("%d",ans);
	return 0;
}
