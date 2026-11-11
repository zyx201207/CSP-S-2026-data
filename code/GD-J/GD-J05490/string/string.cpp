#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	ll ans = 0, sum = 0;
	vector<int> a(n + 1);
	vector<string> b(n + 1);
	string l = "";
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
		for(int j = 1; j <= a[i]; j++) l += b[i];
	}
	for(int i = 1; i <= n; i++) if(l[i] != l[n + 1 - i]) ans++;
	cout << ans;
//oh no... with T1, T3 passed I know nothing about T2
//hopefully this brute algorithm would bring me 10 pts
//210 pts should be enough for a 1= in GD? idk
//11:31 working on the correct algorithm.
//11:51 tried for 20mins, still no idea. ggwp
