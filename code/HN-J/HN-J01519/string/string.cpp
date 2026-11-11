#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1;

ll n, x, ans, sum[26];

char ch;

string s;

bool cmp(ll x, ll y){
	return x > y;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if(n > 10){
		for(int i = 1; i <= n; i++){
			cin >> x >> ch;
			while(x--){
				s += ch;
			}
		}
		ll mid = (s.size() + 2 - 1) / 2;
		for(int i = 0; i < mid; i++){
			if(s[i] != s[s.size() - i]){
				ans++;
			}
		}
		cout << ans;
	}else{
		for(int i = 1; i <= n; i++){
			cin >> x >> ch;
			sum[ch - 'a' + 1] += x;
		}
		sort(sum + 1, sum + 26 + 1, cmp);
		cout << sum[2];
	}
	return 0;
} 
