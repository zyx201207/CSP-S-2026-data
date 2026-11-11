#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 5e5 + 5 ;
int n , m ;
int b[kMaxN] , a[kMaxN] , g[kMaxN] ;
int ve[kMaxN] , lst[kMaxN] , nw ;
int ans[kMaxN] ;
void solve()
{
	cin >> n >> m ;
	int N = 0 ;
	bool fl = 1 ;
	for( int i = 1 ; i <= n ; i++ ) 
	{
		cin >> b[i] ;
		if(b[i] != b[i - 1]) 
		{
			a[++N] = b[i] ;
			g[N] = 1 ;
		}
		else g[N]++ ;
		if(b[i - 1] > b[i]) fl = 0 ;
	}
	if(fl)
	{
		b[n + 1] = 0 ;
		for( int i = 1 ; i <= n ; i++ )
		{
			if(b[i] != b[i + 1])
			{
				cout << i << " " ;
			}
		}
		return ;
	}
	n = N ;
	if(m <= 2)
	{
		for( int i = 1 ; i <= n ; i++ )
		{
			if(a[i] == a[n]) ans[a[i]] += g[i] ;
			else 
			{
				ans[1] += g[i] ;
				ans[2] += g[i] ;
			}
		}
		cout << ans[1] << " " << ans[2] << " " ;
		return ;
	}
	for( int o = 1 ; o <= n ; o++ )
	{
		for( int i = 1 ; i <= m ; i++ ) lst[i] = -1 ;
		nw = 0 ;
		for( int i = o ; i <= n ; i++ )
		{
			if(lst[a[i]] == -1)
			{
				nw++ ;
				ve[nw] = a[i] ;
				lst[a[i]] = nw ;
			}
			else
			{
				for( int j = lst[a[i]] + 1 ; j <= nw ; j++ )
				{
					lst[ve[j]] = -1 ;
				}
				nw = lst[a[i]] ;
			}
		}
		for( int i = 1 ; i <= nw ; i++ ) 
		{
			ans[ve[i]] += g[o] ;
		}
	}
	for( int i = 1 ; i <= m ; i++ ) cout << ans[i] << " " ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

