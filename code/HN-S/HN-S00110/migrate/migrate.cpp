#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 2e6 + 5 ;
int n ;
ll d ;
ll x[kMaxN] ;
bool f[kMaxN] ;
int minn = 1e9 , as = 0 ;
void dfs(int u , int U , int step)
{
	if(step > minn) return ;
	if(u == U)
	{
		if(minn > step)
		{
			minn = step ;
			as = 1 ;
		}
		else if(minn == step) as++ ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		if(f[i]) continue ;
		if(abs(x[i] - x[u]) > d) continue ;
		f[i] = 1 ;
		dfs(i , U , step + 1) ;
		f[i] = 0 ;
	}
}
void solve()
{
	cin >> n >> d ;
	for( int i = 1 ; i <= n ; i++ ) cin >> x[i] ;
	ll cnt = 0 ;
	for( int i = 1 ; i < n ; i++ )
	{
		for( int j = i + 1 ; j <= n ; j++ )
		{
			minn = 1e9 ;
			as = 0 ;
			dfs(i , j , 0) ;
			if(as == 2) cnt++ ;
		}
	}
	cout << cnt << "\n" ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	int oT_To = 1 ;
	cin >> oT_To ;
	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

