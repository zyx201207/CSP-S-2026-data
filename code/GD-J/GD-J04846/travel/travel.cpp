#include <iostream>
#include <string>
using namespace std;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string t2,t4, t1, t3;
	cin >> t1 >> t2 >> t3 >> t4;
	if(t1 == t3)
		if(t2[1] == t4[1] && t2[0] == t4[0])
			if((t2[2] <= 'C' && t2[2] >= 'A' && t4[2] <= 'C' && t4[2] >= 'A') || (t2[2] <= 'F' && t2[2] >= 'D' && t4[2] <= 'F' && t4[2] >= 'D'))
				if((t2[2] - t4[2] == 1 || t2[2] - t4[2] == -1) && !((t2[2] == 'C' && t4[2] == 'D') || (t2[2] == 'D' && t4[2] != 'C')))
					cout << "1111";
				else
					cout << "1110";
			else
				cout << "1100";
		else
			cout << "1000";
	else
		cout << "0000";
}
