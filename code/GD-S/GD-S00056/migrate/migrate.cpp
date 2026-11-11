#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
const long long inf = 4e18;
int c, T;
int n;
long long m, a[N];
long long dis(int i, int j){
	if(i > j) swap(i, j);
	if(i == 0 || j == n+1) return m+1;
	return a[j]-a[i];
}
int fro[N], bac[N];
long long frol[N], bacl[N];
long long s1[N], s2[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		fro[n+1] = bac[n+1] = n+1;
		bacl[n+1] = 0;
		for(int i = n; i >= 1; i--){
			bac[i] = bac[i+1];
			while(dis(i, bac[i]) > m) bac[i]--;
		}
		for(int i = n; i >= 1; i--){
			int t = max(bac[i-1]+1, i+1);
			if(t > bac[i]) bacl[i] = 1;
			else bacl[i] = bac[i]-t+bacl[bac[i]]+1;
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			fro[i] = fro[i-1];
			while(dis(i, fro[i]) > m) fro[i]++;
		}
		for(int i = 1; i <= n; i++){
			int t = min(fro[i+1]-1, i-1);
			if(t < fro[i]) frol[i] = 1;
			else frol[i] = t-fro[i]+frol[fro[i]]+1;
//			cout << fro[i] << ' ' << frol[i] << ' ' << t << '|' << bac[i] << ' ' << bacl[i] << '\n'; 
			s1[i] = s2[i] = 0;
		}
//		assert(max(frol[n]-frol[n-1], bacl[1]-bacl[2]) <= n);
		for(int i = 1; i <= n; i++){
			if(fro[i] < i-1){
				if(bac[fro[i]+1] <= i) 
				s2[fro[i]] += bacl[i];
				else s2[fro[i]]++;
			}
			if(bac[i] > i+1){
				if(fro[bac[i]-1] >= i) 
				s1[bac[i]] += frol[i];
				else s1[bac[i]]++;
			}
		}
		for(int i = 2; i <= n; i++){
			ans += s2[i-1]*s1[i];
		}
		cout << ans << '\n';
	}
	return 0;
} 
