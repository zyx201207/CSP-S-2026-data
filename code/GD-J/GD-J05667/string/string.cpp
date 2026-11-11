#include <bits/stdc++.h>
using namespace std;

char s[200010][3];
int n = 0, tmp[200010];
long long ll = 0;
char chr;


long long count1 (long long a) {
	int c = 0;
	long long d = a;
	for (int i = 1; i <= n; i++) {
		if(d > tmp[i]) {
			c += 1;
			d -= tmp[i];
		} else break;
	}
	return c;
}


int main() {
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i];
		ll += tmp[i];
		cin >> chr;
		s[i][1] = char(tmp[i]);
		s[i][2] = chr;
	}
	if(ll % 2 == 0) {
		for (long long i = 1; i <= ll / 2; i++) {
			if(s[count1(i) + 1][2] != s[count1(ll - i + 1) + 1][2]) {
				ans++;
			}
		} 
	} else {
		for (long long i = 1; i <= ll / 2; i++) {
			if(s[count1(i) + 1][2] != s[count1(ll - i) + 1][2]) {
				ans++;
			} 
		} 
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
