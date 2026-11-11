#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
		cout << "0000";
	else{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] <= 'F' && s2[2] >= 'D'){
				cout << "11";
				return 0;
			}
			else if(s1[2] >='A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
				cout << "1";
			}
			else{
				cout << "00";
				return 0;
			}
			bool flag = false;
			char S = s1[2];
			char S2 = s2[2];
			if(S + 1 == S2 )
				flag |= true;
			if(S - 1 == S2)
				flag |= true;
			cout << flag;
		}
		else{
			cout << "00";
			bool f = false;
			int S1 = (s1[0] - '0') * 10 + (s1[1] - '0');
			int S2 = (s2[0] - '0') * 10 + (s2[1] - '0');
			if(S1 - 1 == S2 && s1[2] == s2[2])
				f |= true;
			if(S1 + 1 == S2 && s1[2] == s2[2])
				f |= true;
			cout << f;
		}
	}
	
	return 0;
} //02 01C 02 01D
