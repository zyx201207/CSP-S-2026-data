#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll ans;
struct ttt
{
	ll num;
	char c;
}  x[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll temp; char c;
		cin >> temp >> c;
		if (!n || x[n].c != c)
			x[++n] = {temp, c};
		else
			x[n].num += temp;
	}
	for (int i = 1, j = n; i < j; )
	{
		ll temp = min(x[i].num, x[j].num);
		if (x[i].c != x[j].c) ans += temp;
		if (temp >= x[i].num) i++;
		else x[i].num -= temp;
		if (temp >= x[j].num) j--;
		else x[j].num -= temp;
	}
	cout << ans;
	return 0;
}
/*


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


-O2



*/
