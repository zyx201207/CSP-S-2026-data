#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, ans = INT_MAX, a[N];

bool cmp(const int &i, const int &j){
	return i > j;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 31; i > 0; i--){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			cnt += (a[j] >> i & 1);
		} 
		if(cnt >= m){
			for(int j = 1; j <= n; j++){
				if(!(a[j] >> i & 1)){
					a[j] = 0;
				}
			}
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= m; i++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
}

