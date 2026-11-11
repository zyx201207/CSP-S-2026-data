#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	char s1[3], s2[3];
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s2[1] == s1[1])
		{
			cout << 1;
			if(s1[2] <= 'C' && s2[2] <= 'C'){
				cout << 1;
				if(s1[2] - s2[2] > 1 || s1[2] - s2[2] < -1){
					cout << 0;
				}
				else{
					cout << 1;
				}
			}
			else if(s1[2] > 'C' && s2[2] > 'C'){
				cout << 11;
			}
			else{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
