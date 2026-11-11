#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,M=5e5+10,DD=25,INF=1e18;
int mx,c,n,m,D,q,w[M],k[N],d[N][N],dd[M][DD],to[M][DD],ct[M];
vector<int>a[N];
vector<int>t[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;++i)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			d[i][j]=INF;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=20;++j)
			dd[i][j]=INF;
	for(int i=1;i<=n;++i)
		d[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];++j)
		{
			int aaa;
			scanf("%lld",&aaa);
			a[i].push_back(aaa);
			int ttt;
			scanf("%lld",&ttt);
			t[i].push_back(ttt);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k[i];++j)
		{
			int aa=a[i][j];
		//	if(aa==1)
				//printf("ddd");
			ct[aa]++;
			mx=max(mx,ct[aa]);
			to[aa][ct[aa]]=i;
			dd[aa][ct[aa]]=min(dd[aa][ct[aa]],w[aa]+t[i][j]);
			//printf("dd[%d][%d]=%d\n",a[i][j],i,dd[a[i][j]][ct[aa]]);
		}		
	}
/*	printf("TO\n");
	for(int i=1;i<=m;++i)
		for(int j=1;j<=ct[i];++j)
			printf("%d ",to[i][j]);*/
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k[i];++j)
		{
			int aa=a[i][j];
			for(int l=1;l<=ct[aa];++l)
			{
				int tt=to[aa][l];
				d[i][tt]=d[tt][i]=min(d[i][tt],t[i][j]+dd[aa][l]-w[aa]);
			}
		}
	}
/*	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			printf("f[%d][%d]=%d\n",i,j,d[i][j]);*/
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
/*	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			printf("f[%d][%d]=%d\n",i,j,d[i][j]);*/
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=INF;
		for(int j1=1;j1<=ct[x];++j1)
			for(int j2=1;j2<=ct[y];++j2)
			{
			//	printf("j1=%d j2=%d\n",j1,j2);
				int tp=dd[x][j1]+dd[y][j2];
			//	printf("2sides:%d %d\n",dd[x][j1],dd[y][j2]);
				if(to[x][j1]!=to[y][j2])
					tp+=d[to[x][j1]][to[y][j2]];
				//printf("upd:from %d to %d to %d to %d,sum is %d\n",x,to[x][j1],to[y][j2],y,tp);
				if(tp<ans)
				{
				//	printf("upd:from %d to %d to %d to %d,sum is %d\n",x,to[x][j1],to[y][j2],y,tp);
					ans=min(ans,tp);
				}
			}
		printf("%lld\n",ans);
	}	
	return 0;
}
