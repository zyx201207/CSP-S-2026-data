#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
constexpr int N=505,M=5e5+5;
int c,n,m,d,q;
int wk[M],dis[N][N];
vector<PI> vec[M];
char ch;
void read(int &res)
{
	res=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		res=(res<<3)+(res<<1)+ch-48;
		ch=getchar();
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++) read(wk[i]);
	for(int i=1,cnt;i<=n;i++)
	{
		dis[i][i]=0;
		read(cnt);
		for(int j=1,a,w;j<=cnt;j++) 
		{
			read(a);read(w);
			vec[a].push_back({i,w}); 
		}
	}
	for(int i=1;i<=m;i++)
	{
		int sz=vec[i].size();
		for(int j=0;j<sz;j++)
		{
			for(int k=j+1;k<sz;k++)
			{
				int u=vec[i][j].first,v=vec[i][k].first;
				dis[u][v]=dis[v][u]=vec[i][j].second+vec[i][k].second;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int l,r,ans=LLONG_MAX;
		read(l);read(r);
		for(PI i:vec[l])
		{
			for(PI j:vec[r])
			{
				ans=min(ans,wk[l]+wk[r]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
