#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int n , m ;
int a[25] ;
int maxn ;
void dfs(int step , int cnt , int ad)
{
	if(cnt > m) return ;
	if(step > n)
	{
		if(cnt == m) maxn = max(maxn , ad) ;
		return ;
	}
	dfs(step + 1 , cnt , ad) ;
	dfs(step + 1 , cnt + 1 , ad & a[step]) ;
}
void solve()
{
	cin >> n >> m ;
	for( int i = 1 ; i <= n ; i++ ) cin >> a[i] ;
	dfs(1 , 0 , (1 << 30) - 1) ; 
	cout << maxn ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("and.in" , "r" , stdin) ;
	freopen("bao.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

