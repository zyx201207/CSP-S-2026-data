#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
const int N = 2e6 + 7;
int n;
ll M, a[N], sum[N];
//sum 是 a 的前缀和 
void init() {
	cin >> n >> M;
	rep(i, 1, n) {
		cin >> a[i];
	}
}
bool check(int k) {
	rep(i, k, n) {
		bool ok = (a[i] * k + sum[i - k] - sum[i] <= M);
		if(ok) return true;
	}
	return false;
}
void countans() {
	sort(a + 1, a + n + 1);
	rep(i, 1, n) {
		sum[i] = sum[i - 1] + a[i];	
	}
	int l = 1, r = n, c = 0;
	int mid = (l + r) >> 1;
	while(l < r) {
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
		mid = (l + r + c) >> 1;
		c = c ^ 1;
	}
	cout << mid << "\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	countans();
	return 0;
}

