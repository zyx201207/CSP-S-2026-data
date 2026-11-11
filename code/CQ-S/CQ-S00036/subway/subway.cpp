#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=508,M=5e5+8;
int C,n,m,d,q,k,x,y,ans,w[M],c[N][N];
int cnt[M],a[M][28],b[M][28];
void chk(int &x,int y)	{x=min(x,y);}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x][++cnt[x]]=i;
			b[x][cnt[x]]=y;
		}
	}
	memset(c,0x3f,sizeof(c));
	for(int i=1;i<=n;i++)	c[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=cnt[i];j++)
			for(int k=j+1;k<=cnt[i];k++)
			{
				chk(c[a[i][j]][a[i][k]],b[i][j]+b[i][k]);
				chk(c[a[i][k]][a[i][j]],b[i][j]+b[i][k]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				chk(c[j][k],c[j][i]+c[i][k]);
	while(q--)
	{
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				ans=min(ans,c[a[x][i]][a[y][j]]+b[x][i]+b[y][j]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
