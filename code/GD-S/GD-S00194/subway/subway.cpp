#include<iostream>//40min，结束。意外地胜利。希望scanf这次别出什么幺蛾子。 
#include<algorithm>
using namespace std;
int c,n,m,d,q,dtk[500010],k,t[500010],pt[500010],cnt,h[500010],nxt[500010],tl[500010],x,y;
long long a[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=5e15;
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++)scanf("%d",&dtk[i]),h[i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			cnt++;
			scanf(" %d %d",&pt[cnt],&t[cnt]);tl[cnt]=i;
			for(int nw=h[pt[cnt]];nw!=-1;nw=nxt[nw])
			{
				a[tl[nw]][i]=a[i][tl[nw]]=min(a[i][tl[nw]],(long long)t[cnt]+t[nw]);
			}nxt[cnt]=h[pt[cnt]],h[pt[cnt]]=cnt;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			if(i!=j&&i!=k)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&x,&y);
		long long ans=5e15;
		for(int nwx=h[x];nwx!=-1;nwx=nxt[nwx])
		{
			for(int nwy=h[y];nwy!=-1;nwy=nxt[nwy])
			ans=min(ans,a[tl[nwx]][tl[nwy]]+dtk[x]+dtk[y]+t[nwx]+t[nwy]);
		}cout<<ans<<endl;
	}
	return 0;
}
