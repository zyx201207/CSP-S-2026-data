#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)? EOF:*p1++)
void read(long long &x)
{
	x=0;
	char c=gc();
	long long f=1;
	while(c>'9'||c<'0') f=(c=='-'? -f:f),c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	x*=f;
}
long long c,n,m,d,q;
long long w[510000];
long long dis[510][510];
vector<pair<long long,long long> > v[510000];
void floyed()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
	{
		read(w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		read(k);
		for(int j=1;j<=k;j++)
		{
			long long a,t;
			read(a),read(t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		long long siz=v[i].size();
		for(int j=0;j<siz;j++)
		{
			for(int k=0;k<j;k++)
			{
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) dis[i][j]=0;
			dis[i][j]=min(dis[i][j],dis[j][i]);
		}
	}
	floyed();
	for(int i=1;i<=q;i++)
	{
		long long x,y,ans=inf;
		read(x),read(y);
		for(auto xt:v[x])
		{
			for(auto yt:v[y])
			{
				ans=min(ans,xt.second+yt.second+dis[xt.first][yt.first]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
