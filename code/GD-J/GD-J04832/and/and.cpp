#include<bits/stdc++.h>
#define ll long long
#define N 200010

using namespace std;
ll n, m, ma, cnt = 0, ans= 0;
ll a;
bool f[N];
ll ch[N][40], dp[40];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	memset(ch, 0, sizeof(ch));
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cnt = 0;
		cin >> a;
		while(a){
			ch[i][++cnt] = a % 2;
			a = a >> 1;
		}
		ma = max(ma, cnt);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= ma - j + 1; ++j){
			swap(ch[i][j], ch[i][ma - j + 1]);
			dp[j] += ch[i][j]; dp[ma - j + 1] += ch[i][ma - j + 1];
			if(j == ma - j + 1) dp[j] -= ch[i][j];
		}
	}
	for(int i = 1; i <= ma; ++i){
		ans = ans << 1;
		if(dp[i] < m) continue;
		ans++;
		for(int j = 1; j <= n; ++j){
			if(!f[j] && !ch[j][i]){
				f[j] = true;
				for(int k = i + 1; k <= ma; ++k){
					if(ch[j][k] == 1) dp[k]--;
					ch[j][k] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
