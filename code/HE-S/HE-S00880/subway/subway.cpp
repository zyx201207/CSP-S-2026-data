#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
struct node{
	int id,t;
};
struct edge{
	int u,v,w;
	bool operator<( const edge &a ) const{
		return w>a.w;
	}
};
int c,n,m,d,q,u,v,la,lt,res,ans,w[M],k[N];
int dep[N],f[N][20],sum[N][20],fa[N];
//c:测试点编号，n:地铁线数，m:地铁站数，d:最多路径数，q:出行计划数。
//w[i]:地铁口 -> 站厅，k[i]:第 i 条路径的地铁站数。
vector<edge>g[N];
vector<node>h[M];
//g[i][j]:从线路 i->j 路径。
//h[i]:{ 第 i 个地铁站所在的线路 ，站厅 -> 第 i 条站台的时间 }。
priority_queue<edge>pq;
int find( int x )
{
	if( fa[x]==x )  return fa[x];
	else  return fa[x]=find( fa[x] );
}
void tree()
{
	int cnt=0;
	while( !pq.empty() )
	{
		int u=pq.top().u,v=pq.top().v,w=pq.top().w;
		pq.pop();
		int x=find( u ),y=find( v );
		if( x==y )  continue;
		fa[x]=y,cnt++;
		g[u].push_back( { u , v , w } );
		g[v].push_back( { v , u , w } );
		if( cnt==n-1 )  break;
	}
}
void dfs( int u , int fu , int t )
{
	dep[u]=dep[fu]+1,f[u][0]=fu,sum[u][0]=t;
	for( int i=1 ; i<=10 ; i++ )
	{
		f[u][i]=f[f[u][i-1]][i-1];
		sum[u][i]=sum[u][i-1]+sum[f[u][i-1]][i-1];
	}
	for( int i=0 ; i<g[u].size() ; i++ )
	{
		int v=g[u][i].v,w=g[u][i].w;
		if( v==fu )  continue;
		dfs( v , u , w );
	}
}
int lca( int u , int v )
{
	int ans=0;
	if( dep[u]<dep[v] )  swap( u , v );
	for( int i=10 ; i>=0 ; i-- )
	{
		if( ( dep[u]-dep[v] )&( 1<<i ) )
			ans+=sum[u][i],u=f[u][i];
	}
	if( u==v )  return ans;
	for( int i=10 ; i>=0 ; i-- )
	{
		if( f[u][i]!=f[v][i] )
		{
			ans+=sum[u][i]+sum[v][i];
			u=f[u][i],v=f[v][i];
		}
	}
	ans+=sum[u][0]+sum[v][0];
	return ans;
}
signed main()
{
	freopen( "subway.in" , "r" , stdin );
	freopen( "subway.out" , "w" , stdout );
	scanf( "%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &q );
	for( int i=1 ; i<=n ; i++ )  fa[i]=i;
	for( int i=1 ; i<=m ; i++ )  scanf( "%lld" , &w[i] );
	for( int i=1 ; i<=n ; i++ )
	{
		scanf( "%lld" , &k[i] );
		for( int j=1 ; j<=k[i] ; j++ )
		{
			scanf( "%lld%lld" , &u , &v );
			h[u].push_back( { i , v } );
			if( j>1 )
			{
				if( h[la].size()>1 )
				{
					for( int k=0 ; k<h[la].size() ; k++ )
					{
						int id=h[la][k].id,t=h[la][k].t;
						if( id==i )  continue;
						pq.push( { id , i , t+lt } );
					}
				}
			}
			la=u,lt=v;
		}
	}
	tree();
	dfs( 1 , 0 , 0 );
	while( q-- )
	{
		scanf( "%lld%lld" , &u , &v );
		ans=1e18;
		for( int i=0 ; i<h[u].size() ; i++ )
		{
			int idu=h[u][i].id,tu=h[u][i].t;
			for( int j=0 ; j<h[v].size() ; j++ )
			{
				int idv=h[v][j].id,tv=h[v][j].t;
				res=lca( idu , idv )+w[u]+w[v]+tu+tv;
				ans=min( ans , res );
			}
		}
		printf( "%lld\n" , ans );
	}
	return 0;
}
