#include<bits/stdc++.h>
using namespace std;
long long n, a, c, d, ans, cnt;
string s1, s2;
string s;
string b;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		cnt += a;
		c = a;
		while(c--) s += b;
	}
	if(n % 2 == 0) d = cnt / 2;
	else d = (cnt + 1) / 2;
	for(int i = 0; i < d; i++) s1 += s[i];
	for(int i = d - 1; i < s.size(); i++) s2 += s[i];
	reverse(s2.begin(), s2.end());
	for(int i = 0; i < d; i++){
		if(s1[i] != s2[i]) ans++;
	}
	cout << ans;
	return 0;
}
