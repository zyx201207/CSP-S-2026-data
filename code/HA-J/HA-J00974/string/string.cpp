#include <bits/stdc++.h>
using namespace std;


long long a , i;
char c;
string S;
int n , ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	while(n--) {
		cin >> a;
		cin >> c;
		for(i = 1; i <= a; i++) {
			S = S + c;
		}
	}
	bool b = true;
	for(i = 1; i <= S.size() / 2; i++) {
		if(S[i - 1] != S[S.size()  - i]) {
			b = false;
			ans++;
		}
	}
	if(b) {
		cout << "0";
	} else {
		cout << ans;
		return 0;
	}
}
