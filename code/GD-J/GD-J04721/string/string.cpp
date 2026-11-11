#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000000 + 5;
string s;
long long n, a[N], tot;
char c[N];
bool flag = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, char> mp;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if(c[i] == c[i - 1]) flag = 1;
		else flag = 0;
		for(int j = 1; j <= a[i]; j++)
		{
			
		}
		tot += a[i];
	}
	if(flag) cout << 0;
	else cout << tot / 2;
	return 0;
}
