#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node
{
	long long a, b;
}b[N];
bool f(node x, node y)
{
	return x.b > y.b;
}
long long n, m, a[N], maxn, k, ans = -1e9;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		maxn = a[i], k = 0;
		for(int j = i; j < n; j++)
		{
			if((maxn & a[j]) > maxn) b[k].a = a[j], b[k].b = (maxn & a[j]) - maxn, k++, maxn = maxn & a[j];
		}
		sort(b, b + k, f);
		maxn = a[i];
		for(int j = 0; j < m; j++) maxn = maxn & b[j].a;
		ans = max(ans, maxn);
	}
	cout << ans;
	return 0;
}
