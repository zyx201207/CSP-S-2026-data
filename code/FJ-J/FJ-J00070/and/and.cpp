#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG

#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

/*
4 2
3 15 12 12

5 3
31 3 1 15 7

4 1
1 6 2 4

4 3
3 31 63 15

4 3
1 6 8 7

5 5
1 5 2 5 7

6 1
1 5 32 76 34 25

5 4
511 127 65535 31 1023

4 3
1 3 5 6

*/

int n,m,ans;
int a[200005];
int vis[200005];
//int arr[200005];

void dfs(int step,int data) {
	if (step > m) {
//		debug("data:%d\n",data);
//		for (int i = 1;i <= m;i++) {
//			debug("%d ",arr[i]);
//		}
//		debug("\n");
		ans = max(ans,data);
		return;
	}
	for (int i = 0;i < n;i++) {
		if (vis[i]) {
			continue;
		}
		vis[i] = 1;
//		arr[step] = a[i];
		dfs(step + 1,data & a[i]);
//		arr[step] = 0;
		vis[i] = 0;
	}
}

bool check(int x) {
	while (x) {
		if ((x & 1) != 1) {
			return false;
		}
		x >>= 1;
	}
	return true;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	if (n <= 20) {
		for (int i = 0;i < n;i++) {
			memset(vis,0,sizeof(vis));
//			arr[1] = a[i];
			vis[i] = 1;
			dfs(2,a[i]);
		}
		cout << ans;
	} else if (m == 1) {
		for (int i = 0;i < n;i++) {
			ans = max(ans,a[i]);
		}
		cout << ans;
	} else if (m == n) {
		ans = a[0];
		for (int i = 1;i < n;i++) {
			ans = ans & a[i];
		}
		cout << ans;
	} else if (m == 2) {
		for (int i = 0;i < n;i++) {
			for (int j= 0;j < n;j++) {
				if (i != j) {
					ans = max(ans,a[i] & a[j]);
				}
			}
		}
		cout << ans;
	} else if (m == n - 1) {
		vector <int> l(n + 1);
		vector <int> r(n + 2);
		for (int i = 0;i < n;i++) {
			if (i == 0) {
				l[i] = a[i];
			} else {
				l[i] = a[i] & l[i - 1];
			}
			
		}
		for (int i = n - 1;i >= 0;i--) {
			if (i == n - 1) {
				r[i] = a[i];
			} else {
				r[i] = a[i] & r[i + 1];
			}
		}
//		debug("l:");
//		for (int i = 0;i < n;i++) {
//			debug("%d ",l[i]);
//		}
//		debug("\n");
//		debug("r:");
//		for (int i = 0;i < n;i++) {
//			debug("%d ",r[i]);
//		}
//		debug("\n");
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (i == 0) {
				ans = max(ans,r[1]);
			} else if (i == n - 1) {
				ans = max(ans,l[n - 2]);
			} else {
				ans = max(ans,l[i - 1] & r[i + 1]);
			}
		}
		cout << ans;
	} else {
		int flag = 1;
		for (int i = 0;i < n;i++) {
			if (!check(a[i])) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			sort(a,a + n);
			ans = a[n - 1];
			for (int i = n - 2;i >= n - m - 1;i--) {
				ans = ans & a[i];
			}
			cout << ans;
		}
	}
	
	
	return 0;
}
