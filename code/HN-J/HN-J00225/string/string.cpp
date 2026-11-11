#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n, ans, a[N];
char c[N];
string s;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	bool flag = true;
	for(int i = 2; i <= n; i++){
		if(c[i] != c[i - 1]) flag = false;
	}
	if(flag == true){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++) s += c[i];
	}
	s = " " + s;
	for(int i = 1; i <= s.size() / 2; i++){
		if(s[i] != s[s.size() - i + 1]) ans++;
	}
    cout << ans << '\n';
	return 0;
}
