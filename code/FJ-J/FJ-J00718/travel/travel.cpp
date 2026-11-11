#include <bits/stdc++.h>
using namespace std;
string ac1, as1, ac2, as2;
int f(string x){
	int ans = 0;
	for (int i = 0; i <= 1; i ++){
		ans *= 10;
		ans += x[i] - '0';
	}
	return ans;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ac1 >> as1 >> ac2 >> as2;
	int c1, s1, y1, c2, s2, y2;
	
	c1 = f(ac1);
	s1 = f(as1);
	y1 = int(char(as1[2]) - 16 - '0');
	
	c2 = f(ac2);
	s2 = f(as2);
	y2 = int(char(as2[2]) - 16 - '0');
	
	if (c1 == c2){
		cout << "1";
		if (s1 == s2){
			cout << "1";
			if ((y1 <= 3 && y2 <= 3) || (y1 >= 4 && y2 >= 4)){
				cout << "1";
				if (abs(y1 - y2) == 1){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	
	return 0;
}
