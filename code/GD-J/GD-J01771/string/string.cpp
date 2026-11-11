#include<iostream>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,a[N],len,ans;
char c[N];
string s;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
		len += a[i];
		for (int j = 1;j <= a[i];j++) {
			s += c[i];
		}
	}
	int st = 0,ed = len - 1,jb = len / 2;
	for (int i = 1;i <= jb;i++) {
		if (s[st] != s[ed]) {
			ans++;
		}
		st++,ed--;
	}
	cout << ans << endl;
	return 0;
}
