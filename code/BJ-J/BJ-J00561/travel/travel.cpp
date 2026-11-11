#include <bits/stdc++.h>
using namespace std;


string c1, s1, c2, s2;
bool f1, f2, f3;

signed main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
	
	string t1, t2;
	char a1, a2;
	for(char c : s1) {
		if(c >= '0' && c <= '9')
			t1 += c;
		else if(c >= 'A' && c <= 'Z')
			a1 = c;
	}
	for(char c : s2) {
		if(c >= '0' && c <= '9')
			t2 += c;
		else if(c >= 'A' && c <= 'Z')
			a2 = c;
	}
	
	if(c1 == c2) {
		f1 = 1;
		cout << "1";
	}
	else {
		f1 = 0;
		cout << "0";
	}
	
	if(f1 == 1 && t1 == t2) {
		f2 = 1;
		cout << "1";
	}
	else {
		f2 = 0;
		cout << "0";
	}
	
	if(f2 == 1 && ((a1 <= 'C' && a2 <= 'C') || (a1 >= 'D' && a2 >= 'D'))) {
		f3 = 1;
		cout << "1";
	}
	else {
		f3 = 0;
		cout << "0";
	}
	
	if(f3 == 1 && (abs(int(a1) - int(a2)) == 1))
		cout << "1";
	else
		cout << "0";
	
	cout << "\n";
	
    return 0;
}
