#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 2147483647;

int n, m, a[N];
int mx, ans, sum_7 = INF;
int A = 1, B = 1;

void dfs(int t, int cnt, int sum) {
	if (t > n || cnt == m) {
		if (cnt == m) ans = max(sum, ans);
		return ;
	}
	if (cnt < m) dfs(t + 1, cnt + 1, sum & a[t]);
	dfs(t + 1, cnt, sum);
}

int main() { // 55 ? 
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
		mx = max(a[i], mx);
		sum_7 &= a[i];
		int lg = log2(a[i] + 1);
		if (lg != (int)lg) A = 0;
		if (a[i] != i - 1) B = 0;
	}
	if (n <= 20) {
		dfs(1, 0, INF);
		cout << ans;
	} else if (m == 1) {
		cout << mx;
	} else if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(a[i] & a[j], ans);
			}
		}
		cout << ans;
	} else if (m == n) {
		cout << sum_7; 
	} else if (A) {
		priority_queue<int> q;
		for (int i = 1; i <= n; i++) {
			q.push(a[i]);
		}
		for (int i = 1; i < m; i++) {
			q.pop();
		}
		cout << q.top();
	} else {
		dfs(1, 0, INF);
		cout << ans;
	}
	return 0;
}

/*
5 3
31 3 1 15 7

4 2
3 15 12 12

*/ 

/*
V 1.0

--- 

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 2147483647;

int n, m, a[N];
int mx; 

bool check(int tgt) {
	int tmp = INF, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if ((tmp & a[i]) >= tgt) {
			cnt++;
			tmp &= a[i];
		}
	}
	return (cnt >= m);
}

int main() {
	freopen("and1.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(a[i], mx);
	}
	int l = 0, r = mx, lst = -1, flg = 0;
	while (l < r) {
		int mid = (l + r) >> 1;
		//cout << mid << endl;
		if (check(mid)) {
			l = mid;
			if (lst == mid) {
				flg = 1;
				break;
			}
			lst = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l + flg;
	return 0;
}
*/ 
