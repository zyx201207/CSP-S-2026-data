#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e5 + 5, M = 2114514;
ll n, ans, sum;
char a[MAXN];
ll s[MAXN], e[MAXN];
ll mj(ll strat, ll end, char m, ll j)
{
	ll i = j , sss = 0;
	for(; strat > e[i]; i++){}
	while(strat <= end)
	{
		if(a[i] != m)
			sss += min(end, e[i]) - strat + 1;
		strat = e[i] + 1;
		i++;
		cout << strat << " " << sss << "\n";
	}
	return sss;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin >> n;
	e[0] = 0;
	s[n + 1] = e[n + 1] = M;
	for(ll i = 1; i <= n; i++)
	{
		ll y;
		cin >> y >> a[i];
		ans += y;
		s[i] = e[i - 1] + 1;
		e[i] = s[i] + y - 1;
	}
	ll ord = 1;
	while(s[ord] <= (ans + 1) / 2)
	{
		ll fe = ans - s[ord] + 1;
		ll fs = ans - e[ord] + 1;
		sum += mj(max(fs, (ans + 1) / 2), fe, a[ord], ord); 
		ord++;
		cout << sum << "\n";
	}
	cout << sum;
	return 0;
} 
