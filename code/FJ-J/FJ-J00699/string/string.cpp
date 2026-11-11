#include<bits/stdc++.h>
using namespace std;
long long n , ss , sss , cd , m , p;
string k , k2;
int main() {
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <long long> a(n + 1);
	vector <char> s(n + 1);
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> s[i];
		ss += a[i];
	}
	if(ss % 2 == 0) {
		sss = ss / 2;
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= a[i] ; j++) {
				if(m < sss) {
					k += s[i];
                    m++;
				} else {
					k2 += s[i];
					p++;
				}
			}
		}
		for(int i = 1 ; i <= sss ; i++) {
			if(k[i] != k2[i]) {
				cd++;
			}
		}
		cout << cd;
	} else {
		sss = ss / 2;
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= a[i] ; j++) {
				if(m < sss) {
					k += s[i];
					m++;
				} else if (p == 0) {
					p++;
				} else {
					k2 += s[i];
				}
			}
		}
		for(int i = 0 ; i < sss ; i++) {
			if(k[i] != k2[i]) {
				cd++;
			}
		}
		cout << cd;
	}
	return 0;
}
