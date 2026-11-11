#include <iostream>
#include <cmath>
using namespace std;

char c1[3], s1[3], c2[3], s2[3];
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0]==c2[0] && c1[1]==c2[1]) {
		cout << "1";
		if (s1[0]==s2[0] && s1[1]==s2[1]) {
			cout << "1";
			if ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')) {
				cout << "1";
				if (abs(s2[2]-s1[2])==1 || (s2[2]=='D'&&s1[2]=='F') || (s1[2]=='D'&&s2[2]=='F'))
					cout << "1\n";
				else cout << "0\n";
			}
			else cout << "00\n";
		}
		else cout << "000\n";
	}
	else {
		cout << "0000\n";
	}
	return 0;
}
