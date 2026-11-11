#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
vector<int> a[505],t[505];
vector<int> dl[500005];
int vis[500005];
long long ans[500005];
void zdl(long long x)
{
	for(int k=1;k<=n;k++)
	{
		long long xx=999999999,yy=0;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]<xx&&vis[i]==0)
			{
				xx=ans[i];
				yy=i;
			}
		}
		if(yy==0)
		{
			return;
		}
		vis[yy]=1;
		int len1=dl[yy].size();
		for(int i=0;i<len1;i++)
		{
			int xz=dl[yy][i];
			int len2=a[xz].size();
			long long z1;
			for(int j=0;j<len2;j++)
			{
				if(a[xz][j]==yy)
				{
					z1=t[xz][j];
					break;
				}
			}
			for(int j=0;j<len2;j++)
			{
				if(a[xz][j]==x||a[xz][j]==yy)
				{
					continue;
				}
				long long zz=ans[yy]+z1+t[xz][j];
				ans[a[xz][j]]=min(ans[a[xz][j]],zz);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++)
	{
		long long k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			dl[x].push_back(i);
		}
	}
	while(q--)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			ans[i]=999999999;
		}
		ans[x]=0;
		zdl(x);
//		for(int i=1;i<=n;i++)
//		{
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
		printf("%lld\n",(ans[y]+w[x]+w[y]));
	}
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
