# include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int n , m , a[N] , c[N] , p[N] , ans[N];
bool flag = 1;
void solve()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] , flag &= a[i] >= a[i - 1];
	for(int i = 1 ; i <= n ; i ++)
	{
		memset(c , 0 , sizeof (int) * (n + 5));
		for(int j = i ; j <= n ; j ++)
		{
			if(c[a[j]]) for(int k = c[a[j]] + 1 ; k < j ; k ++) c[a[k]] = 0;
			c[a[j]] = j;
		}
		for(int j = 1 ; j <= m ; j ++) ans[j] += (bool)c[j];
	}
	for(int i = 1 ; i <= m ; i ++) cout << ans[i] << ' ';
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in" , "r" , stdin); 
	freopen("card.out" , "w" , stdout);
	int t = 1;
	while(t --) solve();
	return 0;
}
