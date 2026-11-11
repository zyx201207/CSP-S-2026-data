#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, ans;
int a[200005];
bool cmp (int x, int y)
{
	return x > y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	ans = a[1];
	for (int i = 2; i <= m ; i++)
	{
		ans &= a[i];
	}
	cout << ans << endl;
	return 0;
}
