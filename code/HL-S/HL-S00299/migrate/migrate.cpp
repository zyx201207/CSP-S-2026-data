#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int c;
ll a[N], d, n, ans = 0;
vector<int> temp;
void sub1112(){
	ll res = 0;
	for(int x = 2; x <= n; x++){
		ll d2 = d/(a[2]-a[1]);
		if(d2 == 0){
			cout << "0\n";
			return;
		}
		if((x-1) % d2 == 0)continue;
		if((x-1) / d2 == 1)res += (n-x+1);
	}
	cout << res << '\n';
	return;
}
void dfs(int now, int tar, int step){
	for(int i = now+1; i <= n && a[i]-a[now] <= d; i++){
		if(i == tar)temp.push_back(step+1);
		dfs(i, tar, step+1);
	}
}
void solve(){
	temp.clear();
	ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i++)cin >> a[i];
	if(c == 11 || c == 12){
		sub1112();
		return;
	}
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			dfs(i, j, 0);
			sort(temp.begin(), temp.end());
			if(temp.size() == 2 && temp[0] == temp[1]){
				ans++;
			}
			if(temp.size() >= 3 && temp[0] == temp[1] && temp[1] != temp[2])ans++;
			temp.clear();
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> c >> T;
	while(T--)solve();
	return 0;
}
