#include<stdio.h>
#include<string.h>
const int N=500005;
using ll=long long;
int idd,n,m,d,q,st[N],sr,a,b;
int poi[N][22],len[N][22],cnt[N];
ll f[505][505];
ll min(ll a,ll b){return a<b?a:b;}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d%d%d",&idd,&n,&m,&d,&q);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	scanf("%d",&st[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sr);
		for(int j=1;j<=sr;j++)
		scanf("%d%d",&a,&b),
		cnt[a]++,poi[a][cnt[a]]=i,
		len[a][cnt[a]]=b;
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<cnt[i];j++)
	for(int k=j+1;k<=cnt[i];k++)
	{
		int x=poi[i][j],y=poi[i][k];
		f[x][y]=f[y][x]=min(f[x][y],
		len[i][j]+len[i][k]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) if(i!=j)
	for(int k=1;k<=n;k++) if(i!=k&&j!=k)
	f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	while(q--)
	{
		scanf("%d%d",&a,&b);ll ans=1e18;
		for(int i=1;i<=cnt[a];i++)
		for(int j=1;j<=cnt[b];j++)
		ans=min(ans,f[poi[a][i]][poi[b][j]]
		+len[a][i]+len[b][j]);printf
		("%lld\n",ans+st[a]+st[b]);
	}
}
