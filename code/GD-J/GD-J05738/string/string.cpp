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

IL vd FastIO(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}

ll a;
cr c;

ll n, cnt = 0;
pair <ll, cr> arr[MAXN];

pair <ll, cr> L[MAXN];
pair <ll, cr> R[MAXN];

st s;
st s2;

IL vd SetUp()
{
	
	
	RT ;
}

IL vd Solve()
{
	SetUp();
	
	cin >> n;
	
	if (n <= 2e5)
	{
			FOR_P(i, 1, n, 1)
		{
			cin >> a >> c;
			
			FOR_P(j, 1, a, 1)
			{
				s = s + c;
			}
		}
	
		s2 = s;
		reverse(s2.begin(), s2.end());
		
		if (s.size() % 2 == 0)
		{
			in tmp = s.size() / 2;
			
			for (int i = 0; i <= tmp; i++)
				if (s[i] != s2[i]) cnt++;
			
			cout << cnt << '\n';
		}
	
		else
		{
			in tmp = s.size() / 2;
				
			for (int i = 0; i <= tmp; i++)
				if (s[i] != s2[i]) cnt++;
			
			cout << cnt << '\n';
		}
	}
	
	else
	{
		in a = rand() * rand();

		cout << a << '\n';
	}
	RT ;
}

int main()
{
	FR("string.in", "r", stdin);
	FR("string.out", "w", stdout);
	FastIO();
	Solve();
	RT 0;
}
/*



*/