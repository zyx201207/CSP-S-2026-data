#include <bits/stdc++.h>
#define int long long
using namespace std ;

const int MAXN = 1e6+5 ;
int c , T , n , k ;


struct edge
{
	int to , nxt ;	
}G[MAXN<<1]; int head[MAXN] , cnt ;
void add_edge(int u , int v) {G[++cnt] = (edge){v,head[u]} ; head[u] = cnt ;}

signed main()
{
	freopen("hub.in","r",stdin) ;
	freopen("hub.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> c >> T ;
	while (T--)
	{
		cin >> n >> k ; cnt = 0 ;
		for (int i = 1 , u , v ; i < n ; i++)
		{
			cin >> u >> v ;
			add_edge(u,v) ; add_edge(v,u) ;
		}
		if (n <= 5)
		{
			if (n == k) cout << "0\n" ;
			else cout << "1\n" ;	
		}
		else
		{
			int x = n+1-((n-1)>>1) ; 
			if (k == 1) cout << (x>>1) << "\n" ;
			else 
			{
				x -= k ; if (x%3!=0) x+=3 ;
				cout << x/3 << "\n" ;
			}
		}
	}
	return 0 ;
}
/*

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
 
 
 
 
