#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 5;

int n, m;
int a[N];
int mns[N];
int premns[N];
int ans = 1;

int getnd(int l, int r){
	return premns[r] - premns[l - 1] - mns[r] * (r - l + 1);
}

int find(int id){
	int l = 1, r = id;
	while (l < r){
		int mid = (l + r) >> 1;
		if (getnd(mid, id) > m){
			l = mid + 1;
		}else {
			r = mid;
		}
	}
	return (l + r) >> 1;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n == 1){
		cout << "1\n";
		return 0;
	}
	sort(a + 1, a + n + 1);
	premns[0] = 0;
	for (int i = 1; i <= n; i++){
		mns[i] = a[n] - a[i];
		premns[i] = premns[i - 1] + mns[i];
	}
	for (int i = 1; i <= n; i++){
		//cout << find(i) << "\n";
		ans = max(ans, i - find(i) + 1);
	}
	cout << ans << "\n";
	return 0;
}
//I want AC plz QWQ.
