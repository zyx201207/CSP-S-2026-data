#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m;
ll a[N], cnt;
bool check(int x){
	int opc = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] < x){
			opc += x - a[i];
		}
		if (opc > m) return false;
	}
	return opc <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = a[n];
	while (l < r){
		int mid = l + (r - l + 1) / 2;
		if (check(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	int eng = r;
	for (int i = 1; i <= n; i++){
		if (a[i] <= eng){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
