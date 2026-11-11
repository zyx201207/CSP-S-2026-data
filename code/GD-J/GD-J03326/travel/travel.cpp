#include <bits/stdc++.h>
using namespace std;
string side(bool car , bool row , char c1 , char c2) {
	if(!(car && row)) return "0";
	if((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'A') || (c1 == 'A' && c2 == 'C')
	|| (c1 == 'C' && c2 == 'A') || (c1 == 'B' && c2 == 'C') || (c1 == 'C' && c2 == 'B')
	|| (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D')) return "1";
	else return "0";
}
string near(bool car , bool row , char c1 , char c2) {
	if(!(car && row)) return "0";
	else if((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'A') || (c1 == 'C' && c2 == 'B')
	|| (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D')) return "1";
	else return "0"; 
}
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string X1 , S1 , X2 , S2;
	cin >> X1 >> S1 >> X2 >> S2;
	cout << ((X1 == X2) ? "1" : "0");
	cout << (((X1 == X2) && S1.substr(0 , 2) == S2.substr(0 , 2)) ? "1" : "0");
	cout << side((X1 == X2) , (S1.substr(0 , 2) == S2.substr(0 , 2)) , S1[2] , S2[2]);
	cout << near((X1 == X2) , (S1.substr(0 , 2) == S2.substr(0 , 2)) , S1[2] , S2[2]);
	return 0;
} 
