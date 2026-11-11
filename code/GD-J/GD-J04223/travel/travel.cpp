#include <bits/stdc++.h>
using namespace std;
int main() {
		
	freopen("travel.in", "s", stdin);
	freopen("travel.out", "w", stdout);

	string a1;
	string a2;
	string b1;
	string b2;
	
	cin >> a1;
	cin >> a2;
	cin >> b1;
	cin >> b2; 
	
	
	
	if(a1[1] == b1[1] && a1[2] == b1[2])cout << 1;
	else {cout << 0 << 0 << 0 << 0 ;;return 0;
	}
	
	if(a2[0] == b2[0] && a2[1] == b2[1])cout << 1;
	else cout << 0;
	
	if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'C' && b2[2] == 'B' ||b2[2] == 'A' )cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'B' && b2[2] == 'C' ||b2[2] == 'A')cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'A' && b2[2] == 'C' ||b2[2] == 'B')cout << 1;
	
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'D' && b2[2] == 'F' )cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'F' && b2[2] == 'D' )cout << 1;
	else cout << 0;
	
	if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'C' && b2[2] == 'B')cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'B' && b2[2] == 'C')cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'B' && b2[2] == 'A')cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'A' && b2[2] == 'B')cout << 1;
	
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'D' && b2[2] == 'F' )cout << 1;
	else if(a2[0] == b2[0] && a2[1] == b2[1] && a2[2] == 'F' && b2[2] == 'D' )cout << 1;
	else cout << 0;
	return 0;
} 
