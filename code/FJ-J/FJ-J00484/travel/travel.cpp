#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    int c1, c11, s1, s11, c2, c22, s2, s22; 
    char x, y;
    cin >> c1;
    cin >> s1 >> x;
    cin >> c2;
    cin >> s2 >> y;
    
    if(c1 == c2) cout << 1;
    else {
    	cout << 0;
    	cout << 0;
    	cout << 0;
    	cout << 0;
    	return 0;
	}
    
    if(s1 == s2) cout << 1;
    else {
    	cout << 0;
    	cout << 0;
    	cout << 0;
    	return 0;
	}
    
    if((x == 'A' || x == 'B' || x == 'C') && (y == 'A' || y == 'B' || y == 'C')) {
    	cout << 1;
	} else if((x == 'D' || x == 'F') && (y == 'D' || y == 'F')) {
		cout << 1;
	} else {
	    cout << 0;
		cout << 0;
		return 0;	
	}
	
	if((x == 'A') && (y == 'B')) cout << 1;
	else if((x == 'B') && (y == 'C')) cout << 1;
	else if((x == 'D') && (y == 'F')) cout << 1;
	else if((y == 'A') && (x == 'B')) cout << 1;
	else if((y == 'B') && (x == 'C')) cout << 1;
	else if((y == 'D') && (x == 'F')) cout << 1;
    else cout << 0;
    
	return 0; 
}
