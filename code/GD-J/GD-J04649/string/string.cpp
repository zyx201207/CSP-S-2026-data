#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;
int ans =0;

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int a;
	char c;
	for (int i = 1;i <= n;i++){
		cin >> a >> c;
		while (a--) s += c;
	}
	ans = 0;
	for (int i = 0;i < s.size() / 2 + 1;i++){
		if (s[i] != s[s.size() - 1 - i]) ans++;
	}
	cout << ans;
} 
