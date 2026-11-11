#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair< long long  , int > PLI;

const int MAXN = 250000;

int fi[MAXN] , ne[MAXN] , to[MAXN] ,cnt=0 ; 
ll wgt[MAXN] , dist[MAXN] ;
bool inq[MAXN];

inline void add(int x,int y,ll w1)
{
	to[ ++cnt ] = y , wgt[cnt] = w1 , ne[cnt] = fi[x] , fi[x] = cnt;
 } 
 
priority_queue< PLI , vector<PLI> , greater<PLI> > Q;

inline ll dijsktra(int s,int t)
{
	memset( dist , 0x3f , sizeof(dist) );
	memset(inq ,false,sizeof(inq));
	dist[s] = 0ll;
	inq[s] = true;
	Q.push(make_pair(0ll,s));
	while(!Q.empty())
	{
		int u=Q.top().second;
		Q.pop();
		for(int y=fi[u];y==0;y=ne[y])
		{
			int v=to[y];
			if(inq[v])continue;
			if(dist[v]>dist[u]+wgt[y])
			{
				dist[v]=dist[u]+wgt[y];
				inq[v]=true;
				Q.push(make_pair(dist[v],v));
			}
		}
	}
	return dist[t];
 } 
 
 inline ll read()
{
	register ll res=0ll,flag=1ll;
	char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch = '-')flag=-1;
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res*flag;
}

int c,m,n,d,q;
ll w[MAXN];
 int main()
 {
 	freopen("subway.in", "r" ,stdin);
	freopen("subway.out.txt", "w" , stdout);
	memset(fi,0,sizeof(fi));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
	int k=read();
	for(int j=1;i<=k;j++)
	{
		int y,w1;
		y=read();w1=read();
		add(m+i,y,w1);
		add(y,m+i,w1);
	}
	}
	for(int i=1;i<=q;i++)
	{
		int x=read();
		int y=read();
		cout<<w[x]+dijsktra(x,y)+w[y]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }