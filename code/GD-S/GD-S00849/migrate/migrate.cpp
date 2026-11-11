#include<bits/stdc++.h>
using namespace std;
int n, l[2000005], r[2000005], L[2000005], R[2000005], L1[2000005], R1[2000005], L2[2000005], R2[2000005];
long long d, x[2000005];
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> x[i];
	for(int i = 1;i <= n;i++) L[i] = R[i] = L1[i] = R1[i] = L2[i] = R2[i] = 0;
	l[0] = 1;
	for(int i = 1;i <= n;i++){
		l[i] = l[i - 1];
		while(x[l[i]] < x[i] - d) l[i]++;
		if(i > l[i]) R1[l[i]]++;
		if(i - 1 > l[i]) R2[l[i]]++;
	}
	r[n + 1] = n;
	for(int i = n;i >= 1;i--){
		r[i] = r[i + 1];
		while(x[r[i]] > x[i] + d) r[i]--;
		if(i < r[i]) L1[r[i]]++;
		if(i + 1 < r[i]) L2[r[i]]++;
	}
	for(int i = 1;i <= n;i++){
		if(l[i] < i && r[l[i]] == i) L[i] = L[l[i]] + L1[l[i]];
	}
	for(int i = n;i >= 1;i--){
		if(r[i] > i && l[r[i]] == i) R[i] = R[r[i]] + R1[r[i]];
	}
	long long ans = 0;
	for(int i = 1;i <= n - 1;i++){
		if(r[i] == r[i + 1] && r[i] > i + 1) R2[i] += R[i];
		if(l[i] == l[i + 1] && l[i + 1] < i) L2[i + 1] += L[i + 1];
		ans += 1ll * L2[i + 1] * R2[i];
	}
	cout << ans << endl;
}
int c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
