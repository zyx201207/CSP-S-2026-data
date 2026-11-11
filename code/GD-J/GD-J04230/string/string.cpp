#include<bits/stdc++.h>
using namespace std;
long long n, u, cnt;
string s, a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> u >> a;
		for(int j = 1; j <= u; j++){
			s = s + a;
		}
	}
	int l = s.size();
	for(int i = 0; i <= (n + 1)/2; i++){
		if (s[i] != s[l - 1 - i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
