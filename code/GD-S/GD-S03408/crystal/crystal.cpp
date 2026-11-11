// Time: 14:44
// !? Craft big Xterfusion !?
# include <algorithm>
# include <iostream>
# define iL inline
# define ll long long
//# define MULTEST
# define FILE
using namespace std;
const int N = 5e5 + 5;
int n;
ll m,a[N];
iL void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	int ans = 0; ll qwq = 0;
	for (int l = 1,r = 1;r <= n;r++){
		qwq += (r - l) * (a[r] - a[r - 1]);
		while (l <= r && qwq > m)
			qwq -= a[r] - a[l],
			l++;
		ans = max(ans,r - l + 1);
	}cout << ans;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	# ifdef FILE
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	# endif
	int x_x_xxx = 1;
	# ifdef MULTEST
	cin >> x_x_xxx;
	# endif
	while (x_x_xxx--)
		solve();
	return 0;
}
