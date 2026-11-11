#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a, b, c, d, a1, b1, c1, d1;
	cin >> a >> b >> c >> d;
	if(a == 02) {
		a1 = 1;
	}else{
		a1 = 0;
	}
	if(b == 01) {
		b1 = 1;
	}else{
		b1 = 0;
	}
	if(c = 02) {
		c1 = 1;
	}else{
		c1 = 0;
	}
	if(d == 01+'B') {
		d1 = 1;
	}else{
		d1 = 0;
	}
	cout << a1 << b1 << c1 << d1;
	return 0;
}
