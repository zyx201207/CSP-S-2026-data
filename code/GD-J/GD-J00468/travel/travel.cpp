#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b; string c, d;
	cin >>a;
	cin >>c;
	cin >>b;
	cin >>d;
	int k1 = c[2] - 'A', k2 = d[2] - 'A';
	if(a == b) cout <<1;
	else cout <<0;
	
	if(c[0] == d[0] && c[1] == d[1] && a == b) cout <<1;
	else cout <<0;
	
	if(c[0] == d[0] && c[1] == d[1] && a == b) {
		if((k1 >= 3 && k2 >= 3) || (k1 <= 2 && k2 <= 1)) cout <<1;
		else cout <<0;
	}
	else cout <<0;
	
	if(c[0] == d[0] && c[1] == d[1] && a == b) {
		if((k1 >= 3 && k2 >= 3) || (k1 <= 2 && k2 <= 1)) {
			if((k1 + 1 == k2) || (k1 - 1 == k2)) {
				cout <<1;
			}
			else cout <<0;
		}
		else cout <<0;
	}
	else cout <<0;
} 
