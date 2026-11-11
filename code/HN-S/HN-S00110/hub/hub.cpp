#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int kMaxN = 1e6 + 5 ;
int n , k ;
vector<int> G[kMaxN] ;
bool f[kMaxN] ;
int p[kMaxN] ;
int minn = 1e9 ;
void get(int u)
{
	if(!p[u]) return ;
	f[u] = 1 ;
	for( int i = 0 ; i < G[u].size() ; i++ )
	{
		int v = G[u][i] ;
		if(f[v]) continue ;
		get(v) ;
	}
}
int gt(int u , int fa)
{
	if(p[u]) return 0 ;
	int minx = 1e9 ;
	for( int i = 0 ; i < G[u].size() ; i++ )
	{
		int v = G[u][i] ;
		if(v == fa) continue ;
		minx = min(minx , gt(v , u) + 1) ;
	}
	return minx ;
}
void dfs(int step , int cnt)
{
	if(cnt > k) return ;
	if(step > n)
	{
		if(cnt == k)
		{
			for( int i = 1 ; i <= n ; i++ ) f[i] = 0 ;
			int cnt = 0 ;
			for( int i = 1 ; i <= n ; i++ )
			{
				if(p[i] && !f[i])
				{
					cnt++ ;
					get(i) ;
				}
			}
			if(cnt > 2) return ;
			int maxn = 0 ;
			for( int i = 1 ; i <= n ; i++ )
			{
				if(!p[i])
				{
					maxn = max(maxn , gt(i , 0)) ;
				}
			}
			minn = min(minn , maxn) ;
		}
		return ;
	}
	p[step] = 1 ;
	dfs(step + 1 , cnt + 1) ;
	p[step] = 0 ;
	dfs(step + 1 , cnt) ;
}
void solve()
{
	cin >> n >> k ;
	for( int i = 1 ; i <= n ; i++ ) G[i].clear() ;
	for( int i = 1 ; i < n ; i++ )
	{
		int u , v ;
		cin >> u >> v ;
		G[u].push_back(v) ;
		G[v].push_back(u) ;
	}
	minn = 1e9 ;
	dfs(1 , 0) ;
	cout << minn << "\n" ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	int oT_To = 1 ;
	cin >> oT_To ;
	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

