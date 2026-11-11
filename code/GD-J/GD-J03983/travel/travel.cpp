#include <bits/stdc++.h> 
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int num1 = c1[0] * 10 + c1[1];
	int num2 = c2[0] * 10 + c2[1];
	if (num1 == num2){
		cout << "1";
		num1 = s1[0] * 10 + s1[1];
		num2 = s2[0] * 10 + s2[1];
		if (num1 == num2){
			cout << "1";
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')){
				cout << "1";
				if (abs(s1[2] - s2[2]) == 1 || (s1[2] > 'C' && s2[2] > 'C')){
					cout << "1\n";
				}
				else{
					cout << "0\n";
				}
			}
			else{
				cout << "00\n";
			}
		}
		else{
			cout << "000\n";
		}
	}
	else{
		cout << "0000\n";
	}
	return 0;
}
