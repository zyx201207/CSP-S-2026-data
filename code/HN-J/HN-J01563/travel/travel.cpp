#include <bits/stdc++.h>
using namespace std;

string a, b, c, d, a1, b1;
bool f = false, f1 = false;
char sum, sum1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		f = true;
	}
	else cout << 0;
	if(b[0] == d[0] && b[1] == d[1] && f){
		cout << 1;
		f1 = true;
	}
	else cout << 0;
	if((b[2] == 'A' && d[2] == 'B' || b[2] == 'A' && d[2] == 'C' || b[2] == 'B' && d[2] == 'C' || b[2] == 'B' && d[2] == 'A' || b[2] == 'C' && d[2] == 'A' || b[2] == 'C' && d[2] == 'B' || b[2] == 'D' && d[2] == 'F' || b[2] == 'F' && d[2] == 'D') && f1)cout << 1;
	else cout << 0;
	if((b[2] == 'A' && d[2] == 'B' || b[2] == 'B' && d[2] == 'A' || b[2] == 'B' && d[2] == 'C' || b[2] == 'C' && d[2] == 'B' || b[2] == 'D' && d[2] == 'F' || b[2] == 'F' && d[2] == 'D') && f1)cout << 1;
	else cout << 0;
	
	return 0;
}
