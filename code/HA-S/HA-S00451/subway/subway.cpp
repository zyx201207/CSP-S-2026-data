#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<3)+(k<<1)+c-'0';
		c=getchar();
	}
	return k*f;
}
struct node{int nex,to;long long val;}edg[2000010];
int h[1000010],cnt=0;
void add(int u,int v,long long ww)
{
	cnt++;
	edg[cnt].nex=h[u];
	edg[cnt].to=v;
	edg[cnt].val=ww;
	h[u]=cnt;
}
long long c,n,m,d,q;
int k[500010];
vector<int> a[500010];
vector<long long> t[500010];
long long w[1010][1010];
long long ww[1000010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) ww[i]=read();
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			w[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			int aa=read(),tt=read();
			a[aa].push_back(i);
			t[aa].push_back(tt);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int kk=0;kk<a[i].size();kk++)
			{
				if(j==kk) continue;
				w[a[i][j]][a[i][kk]]=min(w[a[i][j]][a[i][kk]],t[i][j]+t[i][kk]);
				w[a[i][kk]][a[i][j]]=min(w[a[i][kk]][a[i][j]],t[i][j]+t[i][kk]);
			}
		}
	}
	for(int i=1;i<=n;i++) w[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		long long anss=1e18;
		for(int j=0;j<a[x].size();j++)
		{
			for(int k=0;k<a[y].size();k++)
			{
				anss=min(anss,t[x][j]+t[y][k]+ww[x]+ww[y]+w[a[x][j]][a[y][k]]);
			}
		}
		printf("%lld\n",anss);
	}
	return 0;
}
/*
(bushi,
ye mei ren gao su wo,
zhe di tie neng fan zhe zuo a,
ti mian ye mei shuo a,
kan le kan da yan li cai zhi dao,
(CCF shu da yan li zhen shi yong jiao zao de)

rang wo shang lie qi xing wei da shang ba,
jin nian zai bu shang,jin nian jiu shang bu liao le.
*/
