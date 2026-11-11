#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int N=2e5+5;
ll a[N],ans,maxx;
bool vis[N];
int id[N],cnt[N];
void dfs(int x)
{
	if(x==m+1)
	{
		ans=a[id[1]];
		for(int i=2;i<=m;i++) ans=ans&a[id[i]];
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			id[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
bool cmp(int L,int R) 
{
	return L>R;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=20)
	{
		dfs(1);
		printf("%lld\n",maxx);
	}
	if(n<=2000&&m==1)
	{
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		printf("%lld\n",maxx);
	}
	else if(n<=2000&&m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++) maxx=maxx&a[i];
		printf("%lld\n",maxx);
	}
	else if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		printf("%lld\n",maxx);
	}
	else
	{
		int p=n;
		bool f=1;
		while(p)
		{
			if(p%2==1&&p!=1)
			{
				f=0;
				break;
			}
			p/=2;
		}
		if(f==1)
		{
			for(int i=1;i<=n;i++) if(a[i]!=i-1) f=0;
			if(f==1) printf("%d\n",n-m);
			return 0;
		}
		sort(a+1,a+1+n,cmp);
		maxx=a[1];
		for(int i=2;i<=m;i++) maxx=maxx&a[i];
		printf("%lld\n",maxx);
	}
	return 0;
}
