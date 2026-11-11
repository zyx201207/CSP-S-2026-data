#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
long long s[2000005];
char f;
long long l,ans = 0;;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> f;
		a += f;
	}
	int i = 0,j = n-1;
	while (i != j) {
		if (a[i] == a[j]) {
			s[i] -= min(s[i],s[j]);
			s[j] -= min(s[i],s[j]);
		} else {
			ans += min(s[i],s[j]);
			s[i] -= min(s[i],s[j]);
			s[j] -= min(s[i],s[j]);
		}
		if (s[i] == 0) i++;
		if (s[j] == 0) j--;
	}
	cout << ans;
	return 0;
}