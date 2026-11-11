#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 500000;
ll a[N+8] = {0}, D[N+8] = {0}, P[N+8] = {0};

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a+1, a+n+1);
	bool T = 1, A = 1;
	for(int i = 1;i < n;i++){
		D[i] = a[i+1] - a[i];
		if (T){
			if (D[i] != 0){
				T = 0;
			}
		}if (A){
			if (D[i] != D[i-1] && i > 1){
				A = 0;
			}
		}
	}if (T){
		cout << n;
	}else if(A){
		m /= D[1];
		m *= 2;
		int l = 1, r = sqrt(m) + 1, ans = 0;
		while(l <= r){
			int M = (l + r) / 2;
			if(M * (M + 1) <= m){
				ans = M;
				l = M + 1;
			}else{
				r = M - 1;
			}
		}cout << ans + 1;
	}else{
		for(int i = 1;i <= n;i++){
			P[i] = P[i-1] + a[i];
		}int sum = 0;
		for(int i = 1;i <= n;i++){
			int l = i, r = n, ans = 0;
			while(l <= r){
				int M = (l + r) / 2;
				if((a[M] * (M - i + 1) - (P[M] - P[i-1])) <= m){
					ans = M;
					l = M + 1;
				}else{
					r = M - 1;
				}
			}sum = max(ans - i + 1, sum);
			if (sum + i > n){
				break;
			}
		}cout << sum;
	}
	return 0;
}
