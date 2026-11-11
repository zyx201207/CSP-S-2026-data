#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long

using namespace std;
int n;
string s;
ll L, ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s = ' ' + s;
	for(int i = 1;i <= n;i ++) {
		char c;int a;
		cin >> a >> c;
		L += a;
		for(int j = 1;j <= a;j ++) {
			s += c;
		} 
	}
	for(int i = 1;i <= L / 2;i ++) {
		if(s[i] != s[L + 1 - i]) ans ++;
	}
	cout << ans;
	return 0;
}

