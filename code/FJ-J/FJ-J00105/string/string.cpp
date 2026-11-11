#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
long long A[N+8];
char c[N+8];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> A[i] >> c[i];
	}int l = 1, r = n;
	long long ans = 0;
	long long ls = 0, rs = 0;
	char lc, rc;
	while (l <= r){
		if (ls == 0){
			ls = A[l];
			lc = c[l];
			l++; 
		}if(rs == 0){
			rs = A[r];
			rc = c[r];
			r--;
		}long long res = min(ls, rs);
		if(lc != rc){
			ans += res; 
		}ls -= res;
		rs -= res;
	}cout << ans;
	return 0;
}
