#include <bits/stdc++.h>
#define ST struct
#define FR freopen
#define RT return
#define IL inline

#define FOR_P(i, a, b, c) for (int i = a; i <= b; i += c)
#define FOR_D(i, a ,b, c) for (int i = a; i >= b; i -= c)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using vd = void;
using in = int;
using cr = char;
using st = string;

const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

IL vd FastIO(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}

in n, m;
in arr[MAXN];
in Pre[MAXN];
ll ans = -inf;

IL vd SetUp()
{
	
	
	RT ;
}

IL vd Solve()
{
	SetUp();
	
	cin >> n >> m;
	
	FOR_P(i, 1, n, 1) cin >> arr[i];
	
	sort(arr + 1, arr + n + 1, greater<int>());
	
	FOR_P(i, 1, n - m + 1, 1)
	{
		ll tmp = arr[i];
		FOR_P(j, 1, m - 1, 1)
		{
			// int a = tmp & arr[j + i];
			// cout << arr[i + j] << ' ' << tmp << ' ' << a << '\n';
			tmp = tmp & arr[j + i];
		}
		
		ans = max(ans, tmp);
	}
	
	cout << ans << '\n';
	
	RT ;
}

int main()
{
	FR("and.in", "r", stdin);
	FR("and.out", "w", stdout);
	FastIO();
	Solve();
	RT 0;
}

/*
















3 15 12 12

3 15
15 12
12 12
3 12

3 15
15 12
3 12

dp[i] = ans;

dp[i] & dp[i - 1] max;

dp[1] = 

cmp(a & b)


15 12 12 3

15 12
12 12
12 3




























*/