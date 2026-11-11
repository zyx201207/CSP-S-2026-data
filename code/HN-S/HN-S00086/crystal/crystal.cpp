#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int n, m, a[MAXN], sum[MAXN];
bool check(int k) {
	for(int i = k; i <= n; i++) {
		int l = i - k + 1;
		if(a[i] * k - (sum[i] - sum[l - 1]) <= m) {
			return true;
		}
	}
	return false;
}
int bs() {
	int l = 1, r = n, res = 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1;
			res = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	cout << bs();
	return 0;
} 
//二分答案，显然是最接近的k个数变为相同的最优
//排序然后前缀和计算至少要多少次即可
//一眼了 

//景田标签忘撕了 

//我不落泪 忍住感觉
//分手在起风这个季节
//哭久了会累 也只是别人的以为
//冷的咖啡 我清醒着 一再续杯 
