#include<iostream>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m,a[N],jv = 1,b[N],vis; 
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	string s;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j <= n;j++) {
			bool v = 0;
			s += a[j];
			for (int k = 0;k < s.size();k++) {
				if (s[k] == a[j]) {
					v = 1;
					s[k] = 1;
				}
				if (v) {
					s[k] = 0;
				}
			}
			if (v == 0) {
				s += char(a[j]);
			}
		}
		for (int j = 0;j < s.size();j++) {
			b[s[j]]++;
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}
