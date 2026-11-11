#include<bits/stdc++.h>

using namespace std;

struct stast
{
	int time;
	int nxt;
	int lst;
};

struct sta
{
	stast a[5001];
	int time;
} subw[5001];

int c, n, m, d, q, k;
int w[100001];
bool f[100001];
long long int u, v, b, answ, ans, fsje;

//void dfs( int n, int m )
//{
//	cout << m << " -> ";
//	
//	if( subw[m].a[n].nxt != 0 )
//	{
//		dfs( n, subw[m].a[n].nxt );
//	}
//	
//	return ;
//}

void dfs( int d, int v, int o, int k ) 
{
	if( f[d] == true )
	{
		return ;
	}
	
	if( d == 0 )
	{
		return ;
	}
	
	if( d == v )
	{
		answ = min( ans + subw[d].a[o].time, answ );
		return ;
	}
	
	for( int i = 1; i <= n; i++ )
	{
		ans = k;
		
		if( subw[d].a[i].nxt == 0 )
		{
			continue;
		}
		
		if( subw[d].a[i].nxt == v && i != o )
		{
			answ = min( answ, ans + subw[d].a[o].time + subw[d].a[i].time + subw[v].a[i].time );
			return ;
		}
		if( subw[d].a[i].nxt == v && i == o )
		{
			answ = min( ans + subw[v].a[i].time, answ );
			return ;
		}
		
		if( o != i )
		{
			ans += subw[d].a[o].time;
			ans += subw[d].a[i].time;
		}
		
		if( ans > answ )
		{
			continue;
		}
		
		f[d] = true;
		dfs( subw[d].a[i].nxt, v, i, ans );
		f[d] = false;
		
		
		ans = k;
	}
	
	for( int i = 1; i <= n; i++ )
	{
		ans = k;
		
		if( subw[d].a[i].lst == 0 || subw[d].a[i].time == 0 )
		{
			continue;
		}
		
		if( subw[d].a[i].lst == v && i != o )
		{
			answ = min( answ, ans + subw[d].a[o].time + subw[d].a[i].time + subw[v].a[i].time );
			return ;
		}
		if( subw[d].a[i].lst == v && i == o )
		{
			answ = min( ans + subw[v].a[i].time, answ );
			return ;
		}
		
		if( o != i )
		{
			ans += subw[d].a[o].time;
			ans += subw[d].a[i].time;
		}
		
		if( ans > answ )
		{
			continue;
		}
		
		f[d] = true;
		dfs( subw[d].a[i].lst, v, i, ans );
		f[d] = false;
		
		ans = k;
	}
	
	return ;
}

int main()
{
	freopen( "subway.in", "r", stdin );
	freopen( "subway.out", "w", stdout );
	
	cin >> c >> n >> m >> d >> q;
	
	for( int i = 1; i <= m; i++ )
	{
		cin >> w[i];
		fsje += w[i];
	}
	
	for( int i = 1; i <= n; i++ )
	{
		cin >> k;
		
		for( int j = 1; j <= k; j++ )
		{
			cin >> v >> b;
			
			if( j == 1 )
			{
				subw[v].a[i].time = b;
			}
			else
			{
				subw[v].a[i].time = b;
				subw[u].a[i].nxt = v;
				subw[v].a[i].lst = u;
			}
			
			u = v;
			fsje += b;
		}
	}
	
	for( int i = 1; i <= q; i++ )
	{
		ans = 0;
		answ = fsje;
		cin >> u >> v;
		dfs( u, v, 0, ans );
		cout << answ + w[u] + w[v] << endl;
	}
}

