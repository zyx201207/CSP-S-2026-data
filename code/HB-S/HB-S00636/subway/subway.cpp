#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
long long c,n,m,d,q,k,cc[500005],book[500005],p[500005],booklist[500005],x,y,u,v,w,dis[500005],ans[500005],id=0,len;
vector <int> a[500005],work[500005],list;
int main()
{    
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&cc[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for (int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&x,&y);
			a[m+i].push_back(x);
			a[m+i].push_back(y);
			a[x].push_back(m+i);
			a[x].push_back(y);
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		work[x].push_back(y);
		work[x].push_back(i);
		if (booklist[x]==0)
		{
			booklist[x]=1;
			list.push_back(x);
		}
	}
	len=list.size();
	for (int i=0;i<len;i++)
	{
		x=list[i];
		int head=1,tail=2;
		p[head]=x;
		memset(dis,0x3f,sizeof(dis));
		dis[x]=0;
		while (head<tail)
		{
			u=p[head++];
			book[u]=0;
			int len1=a[u].size();
			for (int j=0;j<len1;j+=2)
			{
				v=a[u][j],w=a[u][j+1];
				if (dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					if (book[v]==0)
					{
						book[v]=1;
						p[tail++]=v;
					}
				}
			}
		}
		int len2=work[x].size();
		for (int j=0;j<len2;j+=2)
		{
			int y=work[x][j],id=work[x][j+1];
			ans[id]=dis[y]+cc[x]+cc[y];
		}
	}
	for (int i=1;i<=q;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
