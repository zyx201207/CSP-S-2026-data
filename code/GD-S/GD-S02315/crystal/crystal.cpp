#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N];
int ans;
int pre[N], sum[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++){
		sum[i] = a[i + 1] - a[i];
	}
	
	bool f = 1;
	for(int i = 1; i < n - 1; i++){
		if(sum[i] != sum[i + 1]) {
			f = 0;
			break;
		}
	}
	if(f){
		int cha = sum[1];
		for(int i = 1; i < n; i++){
			m -= cha * i;
			if(m <= 0){
				cout << i + 1;
				return 0;
			}
		}
	}
	
	ans = 1;
	for(int i = 1; i < n; i++){
		m -= sum[i] * i;
		if(m >= 0) ans++;
	}
	cout << ans;
	return 0;
}

