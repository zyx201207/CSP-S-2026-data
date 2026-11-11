#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N] , l;
void dfs(int u , int v , int b , int d)
{
	if(b < 0) return;
	if(u == v) l++;
	for(int i = u + 1;i <= v;i++)
	{
		if(a[i] - a[u] <= d)
			dfs(i , v , b - 1 , d);
		else break;
	}
}
void solve()
{
	l = 0;
	int n , d , ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 3;j <= n;j++)
		{
			l = 0;
			int next = i , now = i , sum = 0;
			while(next < j)
			{
				next = upper_bound(a + 1 , a + n + 1 , a[now] + d) - a - 1;
//				cout << now << " " << next << endl;
				sum++;
				if(next == now) break;
				now = next;
			}
			if(next < j) break;
			
			dfs(i , j , sum , d);
			if(l == 2)
			{
//				cout << i << "->" << j << " cost:" << sum << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

