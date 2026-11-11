#include <bits/stdc++.h>
#define int long long
#define FOR(i,l,r) for(int i = l;i <= r; i++)
using namespace std;

string str;
string s;

int a[200005];

int ans;
int len;
int n;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b,a%b);
}

#undef int
int main () {
#define int long long

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	
	int g = 0;
	
	FOR(i, 1, n) {
		cin >> a[i];
		if (!g) g = a[i];
		else g = gcd(g, a[i]);
		char c;
		cin >> c;
		s += c; 
	}
	
	s = '*' + s;
	
	FOR(i, 1, n) a[i] /= g;
	
	FOR(i, 1, n) {
		len += a[i];
		while(a[i]--) str += s[i];
	}
	
	str = '*' + str;
	
	FOR(i, 1, len) if (str[i] != str[len - i + 1]) ans++;
	
	cout << ans/2 * g << '\n';
	
//	cout << len << ' ' << g << ' ' << ans << '\n';
//	cout << str;
	
	return 0;
}
/*

10 a	12 a	2 a
5 b		3 b		
3 c		3 c
3 b		5 b
12 a	10 a

len = 33



*/
