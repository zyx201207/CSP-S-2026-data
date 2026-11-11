#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=5010;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,k,ans,a[N],in1[M],in2[M],dis[M],cnt[M];
vector<int>g[M];
queue<int>q;
signed main()
{
	freopen( "migrate.in" , "r" , stdin );
	freopen( "migrate.out" , "w" , stdout );
	scanf( "%lld%lld" , &c , &T );
	while( T-- )
	{
		scanf( "%lld%lld" , &n , &d );
		for( int i=1 ; i<=n ; i++ )  scanf( "%lld" , &a[i] );
		if( n<=5000 )
		{
			k=1,ans=0;
			for( int i=1 ; i<=n ; i++ )  g[i].clear();
			for( int i=1 ; i<=n ; i++ )
			{
				while( k<=n && a[k]-a[i]<=d )  k++;
				for( int j=i+1 ; j<k ; j++ )
					g[i].push_back(j),in1[j]++;
			}
			for( int i=1 ; i<=n ; i++ )
			{
				for( int j=i ; j<=n ; j++ )
					in2[j]=in1[j],dis[j]=INF,cnt[j]=1;
				q.push(i),dis[i]=0;
				while( !q.empty() )
				{
					int u=q.front();
					q.pop();
					for( int j=0 ; j<g[u].size() ; j++ )
					{
						int v=g[u][j];
						if( dis[v]>dis[u]+1 )
							dis[v]=dis[u]+1,cnt[v]=cnt[u];
						else if( dis[v]==dis[u]+1 )  cnt[v]+=cnt[u];
						in2[v]--;
						if( !in2[v] )  q.push( v );
					}
				}
				for( int j=i+1 ; j<=n ; j++ )
					if( cnt[j]==2 )  ans++;
				for( int j=0 ; j<g[i].size() ; j++ )  in1[g[i][j]]--;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
