#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5;

int CCF;
int n;
ll d;
ll a[N];

ll read(){
	ll f = 1, num = 0;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-') f *= -1;
		c = getchar();
	}
	while(isdigit(c)){
		num = num * 10 + (c ^ '0');
		c = getchar();
	}
	return num;
}

void write(ll num){
	if(num < 0){
		putchar('-');
		num = -num;
	}
	putchar(num % 10 + '0');
	if(num > 9) write(num / 10);
}

namespace subtask1{
int dp[N];
ll cnt[N], pre[N];

void Solve(){
	ll ans = 0;
	for(register int i = 1; i <= n; i++){
		fill(dp + 1, dp + 1 + n, 0);
		fill(cnt + 1, cnt + 1 + n, 0);
		fill(pre + 1, pre + 1 + n, 0);
		dp[i] = cnt[i] = pre[i] = 1;
		for(register int j = i + 1, k = i, l = i; j <= n; j++){
			for(; a[j] - a[k] > d; k++){}
			dp[j] = dp[k] + 1;
			for(; dp[k] >= dp[l]; l++){}
			cnt[j] = pre[l - 1] - pre[k - 1];
			pre[j] = pre[j - 1] + cnt[j];
			ans += cnt[j] == 2;
		}
	}
	cout << ans << '\n';
}
}

void Solve(){
	cin >> n >> d;
	for(register int i = 1; i <= n; i++) cin >> a[i];
	if(CCF <= 10) subtask1::Solve();
}

int main(){      
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> CCF >> T;
	while(T--) Solve();
	return 0;
}
/*
 
*/
