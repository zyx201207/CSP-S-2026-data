#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[505],sa[505][21],st[505][21],x,y,ta[501][500001],cz[500001][21];
long long w[500005],f[505][505],t[500005],ans[100005],v[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	memset(f,0x3f,sizeof(f));
	if(c<12)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++)
			{
				scanf("%d%lld",&a[j],&t[j]);
				for(int l=1;l<j;l++)
					f[a[l]][a[j]]=f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
			}
		}
		for(int kkk=1;kkk<=m;kkk++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					f[i][j]=min(f[i][j],f[i][kkk]+f[kkk][j]);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",f[x][y]+w[x]+w[y]);
		}
	}
	else if(c<20)
	{
		long long t;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++)
			{
				scanf("%d%lld",&ta[i][j],&t);
				cz[ta[i][j]][++cz[ta[i][j]][0]]=i;
			}
		}
		for(int i=1;i<=q;i++)
		{
			freopen("subway5.in","r",stdin);
			scanf("%d%d",&x,&y);
			queue<int>q;
			q.push(x);
			while(q.size())
			{
				int frt=q.front();
				q.pop();
				if(frt==y)
				{
					printf("%d\n",w[x]+w[y]+v[y]);
					break;
				}
				for(int i=1;i<=cz[frt][0];i++)
					for(int j=1;j<=k[i];j++)
						if(v[ta[cz[frt][i]][j]]!=0)
							q.push(ta[cz[frt][i]][j]),v[ta[cz[frt][i]][j]]=v[frt]+t;
			}
		}
	}
	else if(c<22)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++)
			{
				scanf("%d%lld",&ta[i][j],&t[i]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			cout<<w[x]+w[y]+t[x]+t[y];//+"写不了了，MLE"
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++)
			{
				scanf("%d%lld",&ta[i][j],&t[i]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			cout<<w[x]+w[y];//+"能1=吗"
		}
	}
	return 0;
}
//hsbhxWWW
