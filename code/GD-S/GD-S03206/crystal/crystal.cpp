#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int>s;
vector<int>d;
vector<int>pr;
bool check(int x){
	int tot = 0;
	for(int i = 1;i <= x;i++){
		tot += pr[x] - pr[i];
	}
	
	if(tot <= m){
		return true;
	}else{
		return false;
	}
}
void solve(){
	cin >> n >> m;
	s.resize(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	sort(s.begin() + 1,s.end());
	
	d.resize(n + 1);
	pr.resize(n + 1);
	for(int i = 2;i <= n;i++){
		d[i] = s[i] - s[i - 1];
		pr[i] = pr[i - 1] + d[i];
	}
	
	int ans = 0;
	int now = 0;
	for(int l = 1,r = 1;l <= n and r <= n;r++){
		now += (r - l) * d[r];
		if(l < r){
			if(now > m){
				l++;
				now -= (pr[r] - pr[l]);
			}else{
				ans = max(ans,(r - l + 1));
			}
		}
	}
	cout << ans << "\n";
	
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
} 
