#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
long long a;
string s, b, x;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a >> b;
		for (int j = 1; j <= a; j ++){
			s += b;
		}
	}
	int len = s.size();
	int lenn = len;
	if (len % 2 == 0){
		lenn = len /2;
	}else{
		lenn = len /2 +1;
	}
	for (int i = lenn; i <= len-1; i ++){
		if (s[i] != s[len -1 -i]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
