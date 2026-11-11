#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool f1, f2, f3, f4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == "01" || c == "01" || a == "16" || c == "16") {
		cout << "0000";
		return 0;
	}
	if(a == c)f1=true;
	if(f1 && b[0] == d[0] && b[1] == d[1])f2=true;
	if(f1 && f2 && ((b[2] == 'A' && (d[2] == 'B' || d[2] == 'C')) || (b[2] == 'B' && (d[2] == 'A' || d[2] == 'C')) || (b[2] == 'C' && (d[2] == 'A' || d[2] == 'B')) || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')))f3=true;
	if(f1 && f2 && f3) {
		if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D'))f4=true;
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
