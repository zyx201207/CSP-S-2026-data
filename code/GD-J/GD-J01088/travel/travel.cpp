#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, x, y;
	cin >> a >> b >> x >> y;
	bool ttt = false;
	if (a == x){
		cout << '1';
		ttt = true;
	}
		else cout <<'0';
	bool f = false;
	if (ttt && b[0] == y[0] && b[1] == y[1]){
		cout << '1';
		f = true;
	}	else cout <<'0';
	int t1, t2;
	if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') t1 = 1;
	else if (b[2] == 'D'|| b[2] == 'F') t1 = 2; 
	if (y[2] == 'A' || y[2] == 'B' || y[2] == 'C') t2 = 1;
	else if (y[2] == 'D'|| y[2] == 'F') t2 = 2; 
	if (f && t1 == t2 && b[2] != y[2]) cout << 1;
	else cout << '0';
	
	//(b[2] == 'A' && y[2] == 'B' || b[2] == 'B' && y[2] == 'A' ||
	// b[2] == 'C' && y[2] == 'B' || b[2] == 'B' && y[2] == 'C' ||
	// b[2] == 'F' && y[2] == 'D' 
	//|| b[2] == 'D' && y[2] == 'F' ||)
	if (f && t1 == t2 && (b[2] + 1 == y[2] || b[2] - 1 == y[2])){
		cout << '1';
	}else cout << '0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
