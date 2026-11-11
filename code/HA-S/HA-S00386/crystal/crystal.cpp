#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 10;

int n;
ll m, a[N], s[N];

int find(int R, ll w){
	int l = 1, r = R, rt = 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(1ll * (R - mid + 1) * w - (s[R] - s[mid - 1]) <= m){
			rt = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return rt;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int res = 1;
	for(int i = 2; i <= n; i++){
		res = max(res, i - find(i - 1, a[i]) + 1);
	}
	cout << res;
	return 0;
}
