#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll ans, a[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while(l < r)
	{
		ll mina = min(a[l], a[r]);
		if(c[l] != c[r])
			ans += mina;
		a[l] -= mina, a[r] -= mina;
		if(a[l] == 0)
			l++;
		if(a[r] == 0)
			r--;
	}
	cout << ans << '\n';
	return 0;
}
