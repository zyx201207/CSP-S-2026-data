#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define uint unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define debug() cout<<"come here\n"
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(int x,char ch)
{
	write(x);
	putchar(ch);
}
vector<pii > e[500005];
int w[500005];
int dis[505][505];
signed main()
{
//	system("fc subway7.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int a=read(),t=read();
			e[a].pb({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			for(int k=1;k<e[i].size();k++)
			{
				dis[e[i][j].first][e[i][k].first]=min(dis[e[i][j].first][e[i][k].first],e[i][j].second+e[i][k].second);
				dis[e[i][k].first][e[i][j].first]=dis[e[i][j].first][e[i][k].first];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	debug();
	while(q--)
	{
		int s=read(),t=read();
		int ans=INF;
		for(auto x:e[s])
		{
			for(auto y:e[t])
			{
				ans=min(ans,dis[x.first][y.first]+x.second+y.second);
//				cout<<x.first<<' '<<y.first<<' '<<x.second<<' '<<y.second<<' '<<dis[x.first][x.second]<<'\n';
			}
		}
//		cout<<w[s]<<' '<<w[t]<<'\n';
		writech(ans+w[s]+w[t],'\n');
	}
	return 0;
}

