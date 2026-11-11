#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10;
int n,m,Max = 0,a[N],cnt[40];vector<int> ans;bool istwo = true,ok = true;

void update() {
	int num = ans[0];
	for (int i = 1;i < ans.size();i++) {
		num &= ans[i];
	}
	Max = max(Max,num);
}

void dfs(int x,int cnt) {
	if (x > n) {
		return;
	}
	if (cnt >= m) {
		update();
		return;
	}
	ans.push_back(a[x]);
	dfs(x + 1,cnt + 1);
	ans.pop_back();
	dfs(x + 1,cnt);
}

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i] != i - 1) {
			ok = false;
		}
		int t = a[i],j = 1;
		while (t) {
			cnt[j] += (t % 2);
			j++;
			t /= 2;
		}
	}
	sort(a + 1,a + n + 1,greater<int>());
	for (int i = 1;i <= n;i++) {
		if (a[i] % 2 != 0) {
			istwo = false;
			break;
		}
	}
	if (n <= 20) {
		dfs(1,0);
		cout << Max << endl;
		cerr << Max << endl;
	} else if (m <= 1) {
		cout << a[1] << endl;
		cerr << a[1] << endl;
	} else if (m <= 2) {
		for (int i = 1;i <= n;i++) {
			for (int j = i + 1;j <= n;j++) {
				Max = max(Max,a[i] & a[j]);
			}
		}
		cout << Max << endl;
		cerr << Max << endl;
	} else if (istwo) {
		cout << a[m] << endl;
		cerr << a[m] << endl;
	} else {
		int ans = 0;
		for (int i = 40;i >= 1;i--) {
			ans += (cnt[i] > m ? 1 : 0);ans *= 2;
		}
		cout << ans << endl;
		cerr << ans << endl;
	}
	return 0;
}