#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6 + 7;
int n, nxt[N], L[N], R[N];
ll D, a[N], sum1[N], sum2[N], sum[N], ans;

int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	int C, T; cin >> C >> T;
	while(T--){
		cin >> n >> D;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) L[i] = R[i] = 0, sum1[i] = sum2[i] = 0;
		nxt[n] = n;
		for(int i = n - 1; i >= 1; --i){
			nxt[i] = nxt[i + 1];
			while(a[nxt[i]] - a[i] > D) nxt[i]--;
			if(nxt[i] != i) L[nxt[i]] = i, R[nxt[i]] = max(R[nxt[i]], i);
		}
		//for(int i = 1; i <= n; ++i) cout << nxt[i] << "\n";
		for(int i = 1; i <= n; ++i){
			sum1[i] = 1;
			if(L[i] == 0 && R[i] == 0) continue;
			sum1[i] += (R[i] - L[i] + 1) + sum1[L[i]] - 1;
		}
		//for(int i = 1; i <= n; ++i) cout << sum1[i] << " ";
		//cout << "\n";
		for(int i = n; i > 1; --i){
			if(nxt[i-1] < nxt[i]){
				sum2[i] = (nxt[i] - nxt[i-1]) + sum2[nxt[i]];
				if(nxt[nxt[i]] == nxt[i] && nxt[nxt[i]-1] < nxt[i]) sum2[i]--;
			}
		}
		//for(int i = 1; i <= n; ++i) cout << sum2[i] << " ";
		//cout << "\n";
		ans = 0;
		for(int i = n; i >= 1; --i){
			sum[i] = 0;
			if(nxt[i] - 1 > i){
				ll tmp = sum2[nxt[i]-1];
				if(nxt[nxt[i]-2] < nxt[i]) tmp--;
				sum[i] = tmp;
				//cout << i << " " << sum1[i] << " " << tmp << "\n";
			}
			if(nxt[i] == i + 1) sum[i] = sum[i+1];
			ans += sum[i];
		}
		cout << ans << "\n";
	}
	return 0;
}