#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	cout << (a == c); 
	cout << (a == c && b[0] == d[0] && b[1] == d[1]);
	cout << (a == c && b[0] == d[0] && b[1] == d[1] && (('A' <= b[2] && b[2] <= 'C' && 'A' <= d[2] && d[2] <= 'C') || ('D' <= b[2] && b[2] <= 'F' && 'D' <= d[2] && d[2] <= 'F')));
	cout << (a == c && b[0] == d[0] && b[1] == d[1] && abs(b[2] - d[2]) == 1 && (b[2] != 'C' && d[2] != 'D') &&  (b[2] != 'D' && d[2] != 'C'));
	return 0;
}//100
