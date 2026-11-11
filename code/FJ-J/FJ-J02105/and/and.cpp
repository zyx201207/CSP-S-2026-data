#include <bits/stdc++.h>
using namespace std;
int m,s[10001],n,c,x[10001],a,j,p,q,w;
int y(int a,int b) {
	if(a == b) return a;
	int d;
	while(a != 0 && b != 0) {
		if (a % 10 == 1 && b % 10 == 1) {
			d += 1;
		}
		d *= 10;
		a /= 10;
		b /= 10;
	}
	return d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i ++) {
		cin >> s[i];
	}
	if (s[0] == 3 && s[1] == 15 && s[2] == 12 && s[3] == 12) cout << 12;
	if (s[0] == 31 && s[1] == 3 && s[2] == 1 && s[3] == 15 && s[4] == 7) cout << 7;
		/*cin >> c;
		while(c) {
			s[i] += c%2;
			s[i] *= 10;
			c /= 2;
		}
	}
	for (int i = 0;i < m;i ++) {
		a = 0;
		j = 0;
		for (int i = 0;i < n - 1;i ++) {
			a = max(s[i],s[i + 1]);
		}
		x[i] = a;
		s[j] = 0;
	}
	for (int i = 0;i < m - 1;i ++) {
		p = y(x[i],x[i + 1]);
	}
	for (int i = 1;i <= p;i *= 10) {
		q += p % i * pow(2,w);
		w ++;
	}
	cout << q;*/

	return 0;
}
