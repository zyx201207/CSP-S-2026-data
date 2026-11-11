#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, ans = 0;
	cin >> n;
	vector<pair<ll, char>> s(n + 1);
	for(int i=1; i<=n; i++) cin >> s[i].first >> s[i].second;
	ll fst = 1, lst = n, hf = s[1].first, hl = s[n].first;
	while(fst <= n && lst > 0){
		if(hf > hl){
			hf -= hl;
			if(s[fst].second != s[lst].second) ans += hl;
			lst--;
			hl = s[lst].first;
		}else if(hl > hf){
			hl -= hf;
			if(s[fst].second != s[lst].second) ans += hf;
			fst++;
			hf = s[fst].first;
		}else{
			if(s[fst].second != s[lst].second) ans += hf;
			fst++, lst--;
			hf = s[fst].first, hl = s[lst].first;
		}
	}
	cout << ans / 2;
    return 0;
}
