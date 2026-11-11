#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e5 + 5 ;
int n ;
struct node
{
	int a ;
	char c ;
}nd[kMaxN] ;
int l , r ;
void solve()
{
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ ) cin >> nd[i].a >> nd[i].c ;
	l = 1 , r = n ;
	ll as = 0 ;
	while(l < r)
	{
		// 计算贡献 
		if(nd[l].c != nd[r].c) as += min(nd[l].a , nd[r].a) ;
		// 推到下一个段
		if(nd[l].a == nd[r].a)
		{
			nd[l].a = nd[r].a = 0 ;
			l++ , r-- ;
		}
		else if(nd[l].a < nd[r].a)
		{
			nd[r].a -= nd[l].a ;
			nd[l].a = 0 ;
			l++ ;
		}
		else
		{
			nd[l].a -= nd[r].a ;
			nd[r].a = 0 ;
			r-- ;
		}
	}
	cout << as ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

