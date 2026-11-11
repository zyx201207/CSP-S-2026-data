#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int N = 2e5 + 5;
int n, l, r;
long long ans = 0;
pair<int, char> p[N];


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;
	
	l = 1, r = n;
	while (l < r)
	{
		int a1 = p[l].first, a2 = p[r].first, c1 = p[l].second, c2 = p[r].second;
		if (a1 > a2)
		{
			if (c1 != c2) ans += a1 - a2;
			p[l].first -= a2;
			r --;
		}
		if (a1 == a2)
		{
			if (c1 != c2) ans += a1;
			l ++, r --;
		}
		if (a1 < a2)
		{
			if (c1 != c2) ans += a2 - a1;
			p[r].first -= a1;
			l ++;
		}
	}
	cout << ans;
	return 0;
 } 

