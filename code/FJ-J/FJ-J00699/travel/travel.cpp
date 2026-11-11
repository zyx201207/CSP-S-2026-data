#include<bits/stdc++.h>
using namespace std;
string n , m , s , k;
long long x , y , h;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> k;
	if(k[2] == 'F'){
		k[2] = 'E';
	}
	if(n == s) {
		cout << 1;
		x++;
	} else {
		cout << 0;
	}
	if(m[0] == k[0] && m[1] == k[1]) {
		cout << 1;
		y++;
	} else {
		cout << 0;
	}
	if(y == 1) {
		if(m[2] <='C' && k[2] <='C') {
			cout << 1;
			h++;
		} else if(m[2] >'C' && k[2] >'C') {
			cout << 1;
			h++;
		} else {
			cout << 0;
		}
	}
	if(x == 1 && y == 1 && h == 1 && abs(m[2] - k[2]) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}

