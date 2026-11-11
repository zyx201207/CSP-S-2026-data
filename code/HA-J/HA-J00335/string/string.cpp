#include <bits/stdc++.h>
using namespace std;

int n;
long long l;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		long long a;
		char c;
		cin >> a >> c;
		for (long long j = 0; j < a; j++){
			s += c;
		}
		l += a;
	}
	long long ans = 0;
	for (long long i = 0; i < l / 2; i++){
		if (s[i] != s[l - i - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}