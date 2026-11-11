//100pts 
#include<bits/stdc++.h>
bool Mst;
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n; ll m;
ll a[N], s[N];
bool check(int k){
//	cerr << "Now check " << k << '\n';
	for(int l = 1; l + k - 1 <= n; ++l){
		int r = l + k - 1;
		ll now = a[r] * (r - l + 1) - (s[r] - s[l - 1]);
//		for(int i = l; i <= r; ++i){
//			now += a[r] - a[i];
//			if(now > m) break;
//		}
//		cerr << "[" << l << ',' << r << "] = " << now << '\n';
		if(now <= m) return 1;
	}
	return 0;
}

bool Med;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cerr << "Memory is " << abs(&Med - &Mst) / 1024.0 / 1024 << "MB.\n";
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	
	return 0;
}
