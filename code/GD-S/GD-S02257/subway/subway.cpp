#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
struct road
{
	int v , w;
	road() {}
	road( const int &v , const int &w ) : v(v) , w(w) {}
	bool operator<( const road &b ) const
	{
		return w < b.w;
	}
};
vector<road> v[500505] , v1[505];
int st[505][505] , st1[505][500005];
priority_queue<road> q;
int a[500005] , dis[505];
bool vis[505];
int main()
{
//	freopen( "subway.in" , "r" , stdin );
//	freopen( "subway.out" , "w" , stdout );
	cin.tie( nullptr );
	cout.tie( nullptr );
	ios::sync_with_stdio( false );
	int c , n , m , d , T;
	cin >> c >> n >> m >> d >> T;
	// 地铁线路数 地铁站数 每个地铁站最多被几条线路经过
	for ( int i = 1 ; i <= m ; i++ ) // m 个车站
		cin >> a[i];
	
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 1 ; j <= n ; j++ )
		{
			if ( i == j )
				continue;
			st[i][j] = 0x7FFFFFFF;
		}
	}
	
	for ( int ui = 1 , num ; ui <= n ; ui++ ) // n 个 
	{
		cin >> num;
		for ( int j = 1 , vi , wi ; j <= num ; j++ )
		{
			cin >> vi >> wi;
			v[ui].emplace_back( vi , wi );
			v[vi].emplace_back( ui , wi );
			st1[ui][vi] = wi; // st -> road
		}
	}
	
	for ( int k = 1 ; k <= m ; k++ ) // mid
	{
		for ( road i : v[k] )
		{
			for ( road j : v[k] )
			{
				if ( !i.w || !j.w || i.v == j.v || i.v <  || j.v < n )
					continue;
				st[i.v][j.v] = min( st[i.v][j.v] , i.w + j.w ); // road -> road
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 1 ; j <= n ; j++ )
		{
			if ( i == j || st[i][j] == 0x7FFFFFFF )
				continue;
			v1[i].emplace_back( j , st[i][j] );
			v1[j].emplace_back( i , st[j][i] );
		}
	}
	
	while ( T-- )
	{
		int ui , vi;
		cin >> ui >> vi;
		memset( vis , 0 , sizeof( vis ) );
		for ( int i = 1 ; i <= n ; i++ )
			dis[i] = 0x7FFFFFFF;
		for ( road i : v )
		{
			q.emplace( i.v , a[ui] + st[i.v][ui + n] );
			dis[i.v] = a[ui] + st[i.v][ui + n];
		}
		while ( !q.empty() )
		{
			int u = q.top().v;
			q.pop();
			if ( vis[u] )
				continue;
			vis[u] = 1;
			for ( road i : v1[u] )
			{
				if ( dis[i.v] > dis[u] + i.w )
				{
					dis[i.v] = dis[u] + i.w;
					q.emplace( i.v , dis[i.v] );
				}
			}
		}
		int ans = 0x7FFFFFFF;
		for ( road i : v[vi] )
		{
			if ( i.v <= n && dis[i.v] != 0x7FFFFFFF )
				ans = min( ans , i.w + dis[i.v] );
		}
		cout << ans + a[vi] << '\n';
	}
	return 0;
}
