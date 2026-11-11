#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 2e5 + 5;

ll n;
ll a[NR];
char c[NR];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s = "";
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(ll j = 1; j <= a[i]; j++) s += c[i];
	}
	string s1 = s;
	reverse(s1.begin(), s1.end());
	ll cnt = 0;
	for(ll i = 0; i < s.size(); i++)
		if(s[i] != s1[i]) cnt++;
	cout << cnt / 2;
	return 0;
}
