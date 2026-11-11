#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long a[N], s[N], m;
int n;

bool check(int x){
	for(int i = x; i <= n; i ++){
		int sr = i-x+1;
		long long res = x * a[i] - (s[i] - s[sr-1]);
		if(res <= m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++)
		s[i] = s[i-1] + a[i];
	int l = 1, r = n, ans = -1;
	while(l <= r){
		int mid = (l+r) / 2;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

