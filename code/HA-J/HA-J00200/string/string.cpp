#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005];
char c[200005];
ll p1, p2, t, ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	p1 = 1, p2 = n;
	while(p1 < p2)
	{
		t = min(a[p1], a[p2]);
		if(c[p1] != c[p2])ans += t;
		a[p1] -= t;
		if(a[p1] == 0)p1++;
		a[p2] -= t;
		if(a[p2] == 0)p2--;
	}
	cout << ans;
	return 0;
}

