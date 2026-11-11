#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll c,n,m,d,q,ans,fr,to,sum1,sum2,k;
ll a2[maxn][20],f[maxn][20],dep[maxn];
struct sj
{
	int x,y,qz;
}a1[maxn];
bool cmp(sj x,sj y)
{
	return x.qz<y.qz;
}
ll find(ll x)
{
	if(f[x][0]==x)
	{
		return x;
	}
	return(f[x][0]);
}
void dfs(int s)
{
	if(f[s][0]==0)
	{
		dep[s]=1;
	}
	dfs(f[s][0]);
	dep[s]=dep[f[s][0]]+1;
}
void tree()
{
	for(int i=1;i<20;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			a2[j][i]=a2[f[j][i-1]][i-1]+a2[j][i-1];
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n+m;i++)
	{
		f[i][0]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a2[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		for(int j=1;j<=2*l;j++)
		{
			scanf("%lld%lld",&fr,&to);
			sj e;
			e.x=i+m;e.y=fr;e.qz=to;
			k++;
			a1[k]=e;
		}
	}
	sort(a1+1,a1+k+1,cmp);
	k=0;
	for(int i=1;i<n+m;i++)
	{
		k++;
		int fx=find(a1[k].x),fy=find(a1[k].y);
		if(fx==fy)
		{
			f[fx][0]=fy;
			a2[x][0]=a1[k].qz;
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		if(dep[i]==0)
		{
			dfs(i);
		}
	}
	tree();
	for(int i=1;i<=q;i+++)
	{
		ans=0;
		cin>>fr>>to;
		sum1=fr;sum2=to;
		if(dep[sum1]>=dep[sum2])
		{
			swap(sum1,sum2);
		}
		for(int j=19;j>=0;j--)
		{
			if(dep[f[sum1][j]]<=dep[sum2])
			{
				sum1=f[sum1][j];
			}
		}
		/*for(int j=19;j>=0;j--)
		{
			if(f[sum1])
		}*/
		cout<<(fr-to)<<endl;
	}
	return 0;
}
