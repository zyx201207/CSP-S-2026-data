#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n;
int a[N];
char c[N];

struct Node {
	int x , id;
	char c;
};

Node find (int x , int op) {
	int cnt = 0;
	Node ans;
	for (int i = 1 ; i <= n ; i++) {
		cnt += a[i];
		if (cnt >= x) {
			ans.x = i;
			if (op == 0) ans.id = a[i] - cnt + x - 1;
			else ans.id = cnt - x + 1;
			ans.c = c[i];
			return ans;
		}
	}
}

signed main () {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i] >> c[i];
	int cnt = 0;
	for (int i = 1 ; i <= n ; i++)
		cnt += a[i];
	if (cnt <= 1e8) {
		string s = "";
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= a[i] ; j++)
				s += c[i];
		int len = s.size();
		s = " " + s;
		if (len & 1) {
			int x = len / 2 + 1 , ans = 0;
			for (int i = x , j = x ; i > 0 && j <= len ; i-- , j++)
				if (s[i] != s[j])
					ans++;
			cout << ans << endl;
		} else {
			int x = len / 2 , ans = 0;
			for (int i = x , j = x+1 ; i > 0 && j <= len ; i-- , j++)
				if (s[i] != s[j])
					ans++;
			cout << ans << endl;
		}
		return 0;
	}
	Node X , Y;
	if (cnt & 1) X = find(cnt / 2 + 1 , 0) , Y = find(cnt / 2 + 1 , 1);
	else X = find (cnt / 2 , 0) , Y = find (cnt / 2 + 1 , 1);
	int l = X.x , r = Y.x , sum1 = X.id , sum2 = Y.id , ans = 0;
//	cerr << sum1 << " " << sum2 << endl;
	char col1 = X.c , col2 = Y.c;
	while (l > 0 && r <= n) {
		if (col1 != col2) ans += min (sum1 , sum2);
		sum1 -= min (sum1 , sum2);
		sum2 -= min (sum1 , sum2);
		if (!sum1) l-- , sum1 += a[l] , col1 = c[l];
		if (!sum2) r++ , sum2 += a[r] , col2 = c[r];
	}
	cout << ans << endl;
	return 0;
}
