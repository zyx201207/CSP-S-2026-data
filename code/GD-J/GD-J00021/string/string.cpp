#include <bits/stdc++.h>
using namespace std;

int n, a, sum = 0;
char c;
string t, s, x;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		getchar();
		cin >> c;
		t.assign(a, c);
		s += t;
	}
	cout << s << '\n';
	x = s;
	reverse(x.begin(), x.end());
	for(int i = 0; i < s.size() / 2; i++){
		if(s[i] != x[i]){
			sum++;
		}
	}
	cout << sum << '\n';
	return 0;
}
