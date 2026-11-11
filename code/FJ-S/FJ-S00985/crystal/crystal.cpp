#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int ll
const int N = 5e5 + 10;
int n, m, a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	sort(a, a + n);
	int mid = a[n / 2], ans = 0;
	for(int i = 0;i < n;i ++){
		ans += abs(mid - a[i]);
		if(ans > m){
			break;
		}
		a[i] = mid;
	}
	int shu = 0;
	for(int i = 0;i < n;i ++){
		if(a[i] == mid){
			shu ++;
		}
	}
	cout << shu;
	return 0;
}
