#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, c1, c2;
	bool a = 0, b = 0, c = 0, d = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		a = 1;
	if(s1[0] + s1[1] == s2[0] + s2[1])
		b = 1;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			c = 1;
	}
	else{
		if(s2[2] == 'D' || s2[2] == 'F')
			c = 1;
	}
	if(s1[2] == 'A'){
		if(s2[2] == 'B')
			d = 1;
	}
	else if(s1[2] == 'B'){
		if(s2[2] == 'A' || s2[2] == 'C')
			d = 1;
	}
	else if(s1[2] == 'C'){
		if(s2[2] == 'B')
			d = 1;
	}
	else if(s1[2] == 'D'){
		if(s2[2] == 'F')
			d = 1;
	}
	else{
		if(s2[2] == 'D')
			d = 1;
	}
	if(a){
		if(b){
			if(c){
				if(d)
					cout << "1111";
				else
					cout << "1110";
			}
			else
				cout << "1100";
		}
		else
			cout << "1000";
	}
	else
		cout << "0000";
	return 0;
}
