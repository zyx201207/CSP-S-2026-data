#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000005;
int c, T, d, nx[N], pr[N], A[N], a[N], fl[N], fr[N], sl[N], sr[N];
int calc(int n){
	for(int i = 0; i <= n + 1; i++) nx[i] = pr[i] = fl[i] = fr[i] = sl[i] = sr[i] = 0;
	for(int i = 1, j = 1; i <= n; i++){
		while(j < n && a[j + 1] - a[i] <= d) j++;
		nx[i] = j;
	}
	for(int i = n, j = n; i; i--){
		while(j > 1 && a[i] - a[j - 1] <= d) j--;
		pr[i] = j;
	}
	for(int i = 1; i <= n - 2; i++)
		if(nx[i] < n && nx[nx[i] - 1] == nx[nx[i]]) fl[i] = 1;
	for(int i = 3; i <= n; i++)
		if(pr[i] > 1 && pr[pr[i] + 1] == pr[pr[i]]) fr[i] = 1;
	for(int i = 1; i < n; i++){
		sl[i]++;
		if(!fl[i]) sl[nx[i]] += sl[i];
	}
	for(int i = n; i > 1; i--){
		sr[i]++;
		if(!fr[i]) sr[pr[i]] += sr[i];
	}
	int ans = 0;
	for(int i = 1; i < n; i++) if(nx[i] < n){
		int lc = sl[i];
		if(nx[i - 1] >= nx[i] - 1) lc = 1;
		ans += (nx[nx[i] - 1] - max(nx[i], nx[nx[i] - 2])) * lc;
		if(fl[i] && (nx[nx[i] - 1] > max(nx[i], nx[nx[i] - 2]))) ans += (sr[nx[nx[i]]] - 1) * lc;
	}
	return ans;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		int n;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> A[i];
		int ans = 0;
		for(int i = 1, ls = 0; i <= n; i++)
			if(A[i + 1] - A[i] > d || i == n){
				for(int j = 1; j <= i - ls; j++) a[j] = A[j + ls];
				ans += calc(i - ls), ls = i;
			}
		cout << ans << '\n';
	}
	return 0;
}

