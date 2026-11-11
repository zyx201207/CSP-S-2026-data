#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, a[N];
long long ans;
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int i = 1, j = n;
	while(i < j)
	{
		int w = min(a[i], a[j]);
		if(c[i] != c[j])
			ans += w;
		a[i] -= w;
		a[j] -= w;
		if(a[i] == 0)
			i++;
		if(a[j] == 0)
			j--;
	}
	cout << ans;
	return 0;
}
