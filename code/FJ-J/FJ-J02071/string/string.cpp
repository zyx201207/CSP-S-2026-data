#include <bits/stdc++.h>
using namespace std;
int n, ans;
void f1() {
	string str;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int a;
		char c;
		cin >> a >> c;
		for(int i = 1;i <= a;i++) str += c;
	}
	for(int i = 0;i < (int)str.size()/2;i++) {
		if(str[i] != str[(int)str.size()-i-1]) ans++;
	}
	cout << ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	f1();
	
	return 0;
}
