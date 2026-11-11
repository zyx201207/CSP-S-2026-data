#include<bits/stdc++.h>
using namespace std;
int last[500005];
int up[10000100];
int v[10000100];
int w[10000100];
int len;
void add(int u,int v,int w)
{++len,
	up[len]=last[u],
	last[u]=len,
	::v[len]=v,
	::w[len]=w;
}
int opt,n,m,d,T;
int W[500005];
long long a[501][501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&opt,&n,&m,&d,&T);
	for(int i=1;i<=m;i++)
		scanf("%d",&W[i]);
	for(int i=1;i<=n;i++)
	{
		int K;scanf("%d",&K);
		for(int j=1;j<=K;j++)
		{
			int A,_t;
			scanf("%d%d",&A,&_t);
			add(A,i,_t);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)a[i][j]=LLONG_MAX/2;
			else a[i][j]=0;
	for(int i=1;i<=m;i++)
		for(int j=last[i];j;j=up[j])
			for(int k=up[j];k;k=up[k])
				a[v[k]][v[j]]=a[v[j]][v[k]]=
					min(a[v[j]][v[k]],1ll*w[j]+w[k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=i+1;j<=n;j++)
					if(j!=k)
						if(a[i][j]>a[i][k]+a[k][j])
							a[j][i]=a[i][j]=a[i][k]+a[k][j];
	while(T--)
	{
		int x,y;long long ans=LLONG_MAX;
		scanf("%d%d",&x,&y);
		for(int j=last[x];j;j=up[j])
			for(int k=last[y];k;k=up[k])
				ans=min(ans,w[j]+a[v[j]][v[k]]+w[k]);//,\
				cerr<<v[j]<<" "<<v[k]<<":"<<w[j]<<"+"<<a[v[j]][v[k]]<<"+"<<w[k]<<"\n";
		printf("%lld\n",W[x]+ans+W[y]);
	}
	return 0;
}
/*129150
5 5
1 2 4 8 9

*/
