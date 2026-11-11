#include<bits/stdc++.h>
#define Code using
#define by namespace
#define wjb std
Code by wjb;
#define int long long
int in()
{
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
void out(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
const int N=5e5+10;
int n,m,d,q;
int w[N];
vector<int>a[510],t[510];
vector<pair<int,int>>lne[N];
int f[510][510];
signed main()
{
//	system("fc subway7.ans subway.out");return 0;
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	in();n=in(),m=in(),d=in(),q=in();
	for(int i=1;i<=m;i++)w[i]=in();
	for(int i=1;i<=n;i++)
	{
		int k=in();
		a[i].resize(k+1),t[i].resize(k+1);
		for(int j=1;j<=k;j++)
		{
			a[i][j]=in(),t[i][j]=in();
			lne[a[i][j]].push_back({i,j});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<(int)a[i].size();j++)
		{
			int u=a[i][j];
			for(int k=0;k<(int)lne[u].size();k++)
			{
				auto p=lne[u][k];
				if(p.first==i)continue;
				f[i][p.first]=min(f[i][p.first],t[i][j]+t[p.first][p.second]);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;cerr<<'\n',i++)for(int j=1;j<=n;j++)cerr<<f[i][j]<<" ";
	while(q--)
	{
		int x=in(),y=in(),ans=1e18;
		for(int i=0;i<(int)lne[x].size();i++)
			for(int j=0;j<(int)lne[y].size();j++)
			{
				int xx=lne[x][i].first,yy=lne[y][j].first;
//				if(xx==yy)cerr<<t[xx][lne[x][i].second]<<" "<<t[yy][lne[y][j].second]<<" !\n";
				ans=min(ans,f[xx][yy]+t[xx][lne[x][i].second]+t[yy][lne[y][j].second]);
			}
		out(ans+w[x]+w[y]),putchar('\n');
	}
	return 0;
}
