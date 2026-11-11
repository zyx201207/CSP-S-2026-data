#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 2e5 + 10;
LL n, m, ans = -INT_MAX, a[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1){
		for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
	}
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	cout << ans;
	return 0;
}
