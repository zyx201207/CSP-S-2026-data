#include <bits/stdc++.h>
using namespace std;
int n, a;
long long cnt, v[200005];
char c;
string s;
map<int, char> mp;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//数组：每个下标有多少个， mp：每个下标对应什么字符  离散化 
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a >> c;
		v[i] = a;
		mp[i] = c;
	}
	int l = 1, r = n;
	while(l <= r) {
		if(v[l] == 0) l ++;
		if(v[r] == 0) r --;
		if(mp[l] != mp[r]) cnt += min(v[r], v[l]);
		v[l] -= min(v[l], v[r]), v[r] -= min(v[l], v[r]);
	}
	cout << cnt;
	return 0;
}
