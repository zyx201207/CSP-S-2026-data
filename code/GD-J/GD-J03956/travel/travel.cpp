#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string a1 , a2 , b1 , b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 != b1)
		cout << "0000";
	else if(a2[0] != b2[0] || a2[1] != b2[1])
		cout << "1000";
	else if((a2[2] - 'A' <= 2 && b2[2] - 'A' > 2) || (a2[2] - 'A' > 2 && b2[2] - 'A' <= 2))
		cout << "1100";
	else if(abs(int(a2[2]) - int(b2[2])) != 1)
		cout << "1110";
	else cout << "1111"; 
	return 0;
} 
