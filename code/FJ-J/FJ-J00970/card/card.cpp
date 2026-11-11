#include <iostream>
#include <queue> 
#include <deque>
using namespace std ;
string name = "card" ;
bool debug = 0 ;//要调0！
const int N = 5 * 1e5 + 5 , M = 3 * 1e5 + 5 ;
int ans[M] , ok[N] , a[N] ;
int n , m ;
deque<int> idx[N] ;
void Main(int id)
{
	int nowidx[N] ;
	deque<int> q ;
	for(int i = 1 ; i <= n ; i ++)
	{
		while(idx[i].front() < id)
			idx[i].pop_front() ;
		nowidx[i] = idx[i].front() ;
	}
	for(int i = id ; i <= n ; i ++)
	{
		if(nowidx[a[i]] != i)
		{
			deque<int> q2 ;
			while(q.front() != a[i])
				q2.push_back(q.front()) , q.pop_front() ;
			while(!q.empty())
			{
				int temp = q.front() ;
				bool flag = 0 ;
				deque<int> q3 ;
				while(!flag)
				{
					if(nowidx[temp] == idx[temp].front())
						flag = 1 ;
					q3.push_back(idx[temp].front()) ;
					idx[temp].pop_front() ;
				}
				nowidx[temp] = idx[temp].front() ;
				while(!q3.empty())
					idx[temp].push_front(q3.back()) , q3.pop_back() ;
				q.pop_front() ;
				ans[temp] -- ;
			}
			while(!q2.empty()) 
				q.push_back(q2.front()) , q2.pop_front() ;
		}
		q.push_back(a[i]) ;
		ans[a[i]] ++ ;
	}
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
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
		idx[a[i]].push_back(i) ;
	}
	for(int i = 1 ; i <= m ; i ++)
		idx[i].push_back(-1) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		Main(i) ;
	}
	for(int i = 1 ; i <= m ; i ++)
		cout << ans[i] << ' ' ;
	cout << '\n' ;
	return 0 ;
}
//yee~
//实则RE  
