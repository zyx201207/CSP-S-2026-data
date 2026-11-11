#include <bits/stdc++.h>
#define ll long long
#define _for(i, x, y) for(int i = x;i <= y;i++)
#define fre(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;
string a, b, c, d;
char x, y;
int main(){
	fre("travel")
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		if(b[0] == d[0] && b[1] == d[1]){
			cout << 1;
			x = b[2];
			y = d[2];
			if((x == 'A' && y == 'B') || (x == 'A' && y == 'C') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'A') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')){
				cout << 1;
				if((x == 'A' && y == 'B') || (x == 'B' && y == 'A') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'D' && y == 'F') || (x == 'F' && y == 'D')) cout << 1;
				else cout << 0, exit(0);
			}
			else cout << "00", exit(0);
		}
		else cout << "000", exit(0);
	}
	else cout << "0000", exit(0);
	return 0;
}
