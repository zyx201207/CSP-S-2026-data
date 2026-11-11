#include <bits/stdc++.h>

using namespace std;

int main (){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w",stdout);
	string a, b, c,d;
	cin >> a >> b >> c >> d;
	
	if (a[1] == c[1] && a[2] == c[2]){
		cout << 1;
	} else {
		cout << 0;
	} if (a == c && (b[1] == d[1] && b[2] == d[2])){
		cout << 1;
	} else {
		cout << 0; 
	} if (a == c && (b[1] == d[1] && b[2] == d[2]) && ((b[3] == 'A' || b[3] == 'B' || b[3] == 'C') && (d[3] == 'A' || d[3] == 'B' || d[3] == 'C'))|| (b[3] == 'D' || b[3] == 'F') && (d[3] == 'D' || d[3] == 'F')){
		cout << 1;
	} else {
		cout << 0;
	} if (a == c && (b[1] == d[1] && b[2] == d[2]) && (((b[3] == 'A' || b[3] == 'B' || b[3] == 'C') && (d[3] == 'A' || d[3] == 'B' || d[3] == 'C'))|| (b[3] == 'D' || b[3] == 'F') && (d[3] == 'D' || d[3] == 'F')) && ((b[3] == 'A' && d[3] == 'B')|| b[3] == 'B' && (d[3] == 'A' || b[3] == 'C') ||( b[3] == 'C' && d[3] == 'B') || (b[3] == 'D' && b[3] == 'F') || (b[3] == 'F' && d[3] == 'D'))){
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}