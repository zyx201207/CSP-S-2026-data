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

IL vd FastIO(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}

IL vd SetUp()
{
	
	
	RT ;
}

IL vd Solve()
{
	SetUp();
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int a = rand() % m;
		cout << a << ' ';
	}
	
	RT ;
}

int main()
{
	FR("card.in", "r", stdin);
	FR("card.out", "w", stdout);
	FastIO();
	Solve();
	RT 0;
}