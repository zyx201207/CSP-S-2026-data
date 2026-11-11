#include <bits/stdc++.h>
using namespace std;
string xc1, xc2, rc3, rc4;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> xc1 >> xc2 >> rc3 >> rc4;
	if (xc1 == rc3) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if ((xc2[0] == rc4[0])&& (xc2[1] == rc4[1])) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if ((xc2[2] <= 'C') && (rc4[2] <= 'C')) cout << 1;
	else{
		cout << "00";
		return 0;
	}
	if (abs((xc2[2]-'A')-(rc4[2]-'A')) == 1) cout << 1;
	else cout << 0; 
	return 0;
}
