#include<bits/stdc++.h>
using namespace std;
long long n , a , ans;
char c;
string s = "";
int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++) {
		cin >> a >> c;
		string add = "";
		add += c;
		long long cnt = 1;
		while(a >= cnt) {
			s += add;
			add += add;
			a -= cnt;
			cnt *= 2;
		}
		while(a) {
			string acc = "";
			acc += c;
			long long cct = 1;
			while(a >= cct) {
				s += acc;
				acc += acc;
				a -= cct;
				cct *= 2;
			}
		}
	}
	long long l = s.size();
	for(long long i = 0;i < l / 2;i++) {
		if(s[i] != s[l - i - 1]) ans++;
	}
	cout << ans;
	return 0;
}
