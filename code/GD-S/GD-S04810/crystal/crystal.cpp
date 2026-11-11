#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, dif;
	ll m;
	cin >> n >> m;
	vector<ll> a(n + 1), diff(n + 1), pref(n + 1), ans;
	vector<pair<int, int>> cord;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
	for(int i = 2; i <= n; i++) // selecting the i_th element in the array
	{
		for(int j = 1; j < i; j++) // unselecting the j_th element in the array
		{
			dif = 0;
			dif = (i - j) * a[i] + pref[j - 1] - pref[i - 1];
			if(dif > 0 && dif <= m)
			{
				ans.push_back(i - j + 1);
			}
		}
	}
	cout << *max_element(ans.begin(), ans.end());
	return 0;
}
//froepen("crysatl", "w", stdin)
//It's really a shame that it's 17:49 now and I've got 50pts only from this brute method
//But nvm.. I spent only 1 year studying OI. With the estimated result of the J group,
//which is 210pts, it's been acceptable to me, who just viewed OI as an inspration.
//This only year studying OI has been like an illusion, passing so quickly,
//while it's doubtless that I'm going AFO soon.
//anyway, ggwp. God bless you.
