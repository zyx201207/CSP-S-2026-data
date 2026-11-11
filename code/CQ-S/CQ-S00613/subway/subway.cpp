#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
const long long inf=1e18;
int w[M];
pair<int,int> s[M][24];
int siz[M];
long long f[N][N];
inline void read(int &ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') 
	{
		ret=ret*10+ch-'0';
		ch=getchar();
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++)
	{
		int len;
		read(len);
		for(int j=1;j<=len;j++)
		{
			int x,y;
			read(x),read(y);
			s[x][++siz[x]]={y,i};
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int len=siz[i];
		for(int j=1;j<=len;j++)
		{
			int tj=s[i][j].first;
			int idj=s[i][j].second;
			for(int k=j+1;k<=len;k++)
			{
				int tk=s[i][k].first;
				int idk=s[i][k].second;
				if(tj+tk<f[idj][idk]) f[idj][idk]=f[idk][idj]=tj+tk;
			}
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
		int u,v;
		read(u),read(v);
		long long ans=inf;
		for(int i=1;i<=siz[u];i++)
		{
			int idi=s[u][i].second;
			int ti=s[u][i].first;
			for(int j=1;j<=siz[v];j++)
			{
				int idj=s[v][j].second;
				int tj=s[v][j].first;
				ans=min(ans,1ll*w[u]+w[v]+f[idi][idj]+ti+tj);
			}
		}
		printf("%lld\n",ans);
	}
}
