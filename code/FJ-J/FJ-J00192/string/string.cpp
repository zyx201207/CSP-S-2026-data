#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
pair <int, char> a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	int l = 1, r = n;
	long long ans = 0;
	while(l < r){
		int x = a[l].first, xx = a[r].first;
		int y = a[l].second, yy = a[r].second;
		int k = min(x, xx);
		if(y != yy) ans += k;
		a[l].first -= k;
		a[r].first -= k;
		if(a[l].first == 0) l++;
		if(a[r].first == 0) r--;
	}
	cout << ans;
	return 0;
}

