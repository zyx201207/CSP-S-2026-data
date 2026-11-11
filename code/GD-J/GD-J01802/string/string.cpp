#include<bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MAXN = 200005;

int n;
ll L = 0;
ll cnt[MAXN];
char c[MAXN];
ll ans = 0;
ll pass = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> cnt[i] >> c[i],
		L += cnt[i];
	
	for(ll l = 1, r = n, cntl = 0, cntr = 0; ; ){
		if(c[l] != c[r]){
			ll suml = cnt[l] - cntl, sumr = cnt[r] - cntr;
			if(suml == sumr) l++, cntl = 0, r--, cntr = 0, ans += suml;
			else if(suml > sumr) cntl += sumr, r--, cntr = 0, ans += sumr;
			else l++, cntl = 0, cntr += suml, ans += suml;
		}else{
			ll suml = cnt[l] - cntl, sumr = cnt[r] - cntr;
			if(suml == sumr) l++, cntl = 0, r--, cntr = 0, pass += suml;
			else if(suml > sumr) cntl += sumr, r--, cntr = 0, pass += sumr;
			else l++, cntl = 0, cntr += suml, pass += suml;
		}
		if(ans + pass >= (L + 1ll) / 2ll) break;
	}

	cout << ans;
}
