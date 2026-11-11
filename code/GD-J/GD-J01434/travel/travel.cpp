#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else cout << 0;
	if(a == c && b[0] == d[0] && b[1] == d[1]) cout << 1;
	else cout << 0;
	if(a == c && b[0] == d[0] && b[1] == d[1]){
		bool flag = false;
		if(b[2] == 'A' && d[2] == 'B') flag = true;
		else if(b[2] == 'A' && d[2] == 'C') flag = true;
		else if(b[2] == 'B' && d[2] == 'A') flag = true;
		else if(b[2] == 'B' && d[2] == 'C') flag = true;
		else if(b[2] == 'C' && d[2] == 'A') flag = true;
		else if(b[2] == 'C' && d[2] == 'B') flag = true;
		else if(b[2] == 'D' && d[2] == 'F') flag = true;
		else if(b[2] == 'F' && d[2] == 'D') flag = true;
		if(flag) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	if(a == c && b[0] == d[0] && b[1] == d[1]){
		bool flag = false;
		if(b[2] == 'A' && d[2] == 'B') flag = true;
		else if(b[2] == 'B' && d[2] == 'A') flag = true;
		else if(b[2] == 'B' && d[2] == 'C') flag = true;
		else if(b[2] == 'C' && d[2] == 'B') flag = true;
		else if(b[2] == 'D' && d[2] == 'F') flag = true;
		else if(b[2] == 'F' && d[2] == 'D') flag = true;
		if(flag) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0;
} 
