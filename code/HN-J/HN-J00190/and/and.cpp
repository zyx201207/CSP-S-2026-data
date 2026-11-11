# include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n , m , tmp , maxn , a[N] , s[N] , p[N];
bool flag = 1;
void dfs(int x , int y , LL ans)
{
	if(x > n)
	{
		maxn = max(maxn , ans);
		return ;
	}
	if(y + n - x >= m) dfs(x + 1 , y , ans);
	dfs(x + 1 , y + 1 , (!y ? a[x] : (ans & a[x])));
	return ;
}
void solve()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] , tmp = a[i];
		while(tmp)
		{
			if(!flag) break;
			flag &= !(tmp % 2);
			tmp /= 2;
		}
		maxn = max(maxn , a[i]);
	}
	if(flag)
	{
		sort(a + 1 , a + n + 1 , greater <int> ());
		cout << a[m];
		return ;
	}
	if(maxn < 4)
	{
		int c[4] = {0};
		for(int i = 1 ; i <= n ; i ++) c[a[i]] ++;
		if(c[3] >= m) cout << 3;
		else if(c[3] + c[2] >= m) cout << 2;
		else if(c[3] + c[1] >= m) cout << 1;
		else cout << 0; 
		return ;
	}
	maxn = 0;
	if(m == 1)
	{
		for(int i = 1 ; i <= n ; i ++) maxn = max(maxn , a[i]);
		cout << maxn;
		return ;
	}
	if(m == 2)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++)
			{
				maxn = max(maxn , (a[i] & a[j]));
			}
		}
		cout << maxn;
		return ;
	}
	if(m == n - 1)
	{
		s[1] = a[1] , p[n] = a[n];
		for(int i = 2 ; i <= n ; i ++) s[i] = s[i - 1] & a[i];
		for(int i = n - 1 ; i >= 2 ; i --) p[i] = p[i + 1] & a[i];
		for(int i = 2 ; i < n ; i ++) maxn = max(maxn , s[i - 1] & p[i + 1]);
		maxn = max(maxn , s[n - 1]) , maxn = max(maxn , p[2]);
		cout << maxn;
		return ;
	}
	if(m == n)
	{
		for(int i = 1 ; i <= n ; i ++) maxn &= a[i];
		cout << maxn;
		return ;
	}
	dfs(1 , 0 , 0);
	cout << maxn;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in" , "r" , stdin); 
	freopen("and.out" , "w" , stdout);
	int t = 1;
	while(t --) solve();
	return 0;
}
