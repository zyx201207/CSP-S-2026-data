#include <bits/stdc++.h>
using namespace std ;

const int N = 505 , K = 1005 ;
int c , n , m , d , q , w [N] , k [N] , a [N] [K] , t [N] [K] , dis [K] [K] ;
vector <int> wqx [K] ;

struct Node
{
	int id , sum ;
	// 这个站台以及到达这个站台所需要的时间 
} ;

void bfs (int x)
{
	queue <Node> q ;
	q . push (Node {x , w [x]}) ;
	dis [x] [x] = w [x] ;
	while (! q . empty ())
	{
		int id = q . front () . id , sum = q . front () . sum ;
		q . pop () ;
		for (int i = 1 ; i <= k [id] ; i ++)
		{ 
//			cout << "从" << x << " " << "到" << a [id] [i] << "的时间为" << sum << "+" << t [id] [i] << endl ;
			for (auto j : wqx [id])
			{ 
				if (sum + t [id] [i] + t [i] [j] > dis [x] [a [id] [i]])
					continue ;
				dis [x] [a [id] [i]] = sum + t [id] [i] + t [i] [j] ;
				q . push (Node {a [id] [i] , sum + t [id] [i] + t [i] [j]}) ;
			}
		}
	}
}

int main ()
{
	freopen ("subway.in" , "r" , stdin) ;
	freopen ("subway.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	memset (dis , 0x3f , sizeof (dis)) ;
	cin >> c >> n >> m >> d >> q ;
	for (int i = 1 ; i <= m ; i ++)
		cin >> w [i] ;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> k [i] ;
		for (int j = 1 ; j <= k [i] ; j ++)
			cin >> a [i] [j] >> t [i] [j] , wqx [a [i] [j]] . push_back (i) ;
	}
	for (int i = 1 ; i <= n ; i ++)
		bfs (i) ;
//	for (int i = 1 ; i <= m ; i ++)
//	{
//		cout << "入口分别到达" << i << "的时间：" ; 
//		for (int j = 1 ; j <= n ; j ++)
//			cout << dis [i] [j] << " " ;
//		cout << "\n" ;
//	}
	while (q --)
	{
		int x , y ;
		cin >> x >> y ;
		cout << dis [x] [y] + w [y] << endl ;
	}
	return 0 ;
}

