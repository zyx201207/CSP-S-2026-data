#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long
const int N = 2e5+5;
int a[N];
vector<int> num[35];
bool ins[N],inv[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int j = 30; j >= 0; j--)
		{
			if (a[i]&(1<<j)) num[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) ins[i] = 1;
	ll ans = 0;
	for (int j = 30; j >= 0; j--)
	{
		if (num[j].size() < m) continue;
		for (int i = 1; i <= n; i++) inv[i] = 0;
		int sz = 0;
		for (int v : num[j])
		{
			inv[v] = 1;
			if (ins[v]) sz++;
		}
		if (sz < m) continue;
		ans += (1<<j);
		for (int i = 1; i <= n; i++) if (ins[i] && !inv[i]) ins[i] = 0;
	}
	cout << ans;
	return 0;
}
