#include<bits/stdc++.h>
#define N 505
#define M 500005
#define fir first
#define sec second
#define MP make_pair
using namespace std;
using ll=long long;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int c,n,m,D,q,k[N];
ll w[M],f[N][N];
vector<int> a[N];
vector<ll> t[N];
vector<pair<int,ll>> d[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),D=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		a[i].resize(k[i]+5),t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++) a[i][j]=read(),t[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			int now=a[i][j];
			d[now].push_back(MP(i,t[i][j]));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int p1=0;p1<d[i].size();p1++) for(int p2=0;p2<d[i].size();p2++)
		{
			int j=d[i][p1].fir,k=d[i][p2].fir;
			if(j==k) continue;
			ll x=d[i][p1].sec,y=d[i][p2].sec;
			f[j][k]=min(f[j][k],x+y);
			f[k][j]=min(f[k][j],x+y);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int s=read(),t=read();
		ll mn=2e18;
		for(int p1=0;p1<d[s].size();p1++) for(int p2=0;p2<d[t].size();p2++)
		{
			int i=d[s][p1].fir,j=d[t][p2].fir;
			ll x=d[s][p1].sec,y=d[t][p2].sec;
			mn=min(mn,w[s]+w[t]+x+y+f[i][j]);
		}
		printf("%lld\n",mn);
	}
	return 0;
}

