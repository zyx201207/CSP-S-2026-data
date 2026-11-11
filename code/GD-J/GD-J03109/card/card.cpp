#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define int long long
int n, m;
int a[N];
int vis[N], card[N];
int ans[N];
bool spe_A = 1, spe_B = 1;
int cnt_speB = 0;
int lst[N];

void solve1(int idx)
{
	for(int i = 1; i <= n; i++) card[i] = 0, vis[i] = 0, lst[i] = 0;
	int l = 0;
	for(int i = idx; i <= n; i++)
	{
		if(vis[a[i]])
		{
			int pre_l = l;
			l = lst[a[i]]-1;
			for(int j = lst[a[i]]; j <= pre_l; j++)
			{
				vis[card[j]] = 0;
				lst[card[j]] = 0;
				card[j] = 0;
			}
		}
		card[++l] = a[i];
		vis[a[i]] = 1;
		lst[a[i]] = l;
	}
	for(int i = 1; i <= m; i++)
	{
		if(vis[i]) ans[i]++;
	}
}

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] < a[i-1]) spe_A = 0;
		if(i > 1 && a[i] != a[i-1] && spe_B) cnt_speB++;
		if(cnt_speB > 4999) spe_B = 0;
	}
	if(spe_A)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[i+1]) lst[a[i]] = i;
		}
		for(int i = 1; i <= m; i++)
		{
			cout << lst[i] << " ";
		}
		cout << endl;
		return 0;
	}
	if(m == 2)
	{
		if(n == 1) ans[a[1]]++;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[n]) ans[a[i]]++, ans[a[n]]++;
			else ans[a[n]]++;
		}
		for(int i = 1; i <= m; i++) cout << ans[i] << " ";
		cout << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) solve1(i);
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
