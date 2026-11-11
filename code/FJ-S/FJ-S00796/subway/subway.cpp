#include <iostream>
#include <vector>
using namespace std ;
string name = "subway" ;
bool debug = 0 ;//上交时为0！
const int M = 5 * 1e4 + 5 ;
const int N = 505 ;
int m , n , d , q ;
//int w[M] , k[N] , line[N][M] , t[N][M] ;
vector<int> w(M) , k(N) ;
int line[N][M] , t[N][M] ;
vector<int> hc[M] , dis[M] ;
vector<bool> vis[M] ;
void csh()
{
	for(auto i : vis)
		i.resize(m + 5) ;
}
int main()
{
    if(!debug)
	{
		string inname = name + ".in" ;
		string outname = name + ".out" ;
		freopen(inname.c_str() , "r" , stdin) ;
		freopen(outname.c_str() , "w" , stdout) ;
	}
	cin >> n >> n >> m >> d >> q ;
	csh() ;
	for(int i = 1 ; i <= m ; i ++)
		cin >> w[m] ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k[i] ;
		for(int j = 1 ; j <= k[i] ; j ++)
		{
			cin >> line[i][j] >> t[i][j] ;
			//hc[line[i][j]].push_back(i) ;
			for(int k2 = 1 ; k2 < j ; k2 ++)
				dis[k2][j] = dis[j][k2] = t[i][j] + t[i][k2] ;
			dis[j][j] = 0 ;
		}
	}
	
	while(q --)
	{
		int x , y ;
		cin >> x >> y ;
		int iocost = w[x] + w[y] ;
		if(dis[x][y] != -1)
		{
			cout << iocost + dis[x][y] ;
			continue ;
		}
		int ans = 1e9 ;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(dis[x][i] != -1 && dis[i][y] != -1)
				ans = min(ans , dis[x][i] + dis[i][y]) ;
		}
		cout << ans ;
	}
	return 0 ;
}
//yee~
