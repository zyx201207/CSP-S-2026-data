#include<bits/stdc++.h>
using namespace std;
string c[3], s[3];
char d[3][2] = {{'A', 'B'}, {'B', 'C'}, {'D', 'F'}};
char q[3] = {'A', 'B', 'C'};
int finda(char a){
	for(int i = 0;i < 3;i++){
		if(a == q[i]) return 1;
	}
	return 2;
}
bool checkab(char a, char b){
	for(int i = 0;i < 3;i++){
		if((a == d[i][0] && b == d[i][1]) || (a == d[i][1] && b == d[i][0])) return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c[1] >> s[1] >> c[2] >> s[2];
	if(c[1] == c[2]){
		cout << '1';
		if(s[1][0] == s[2][0] && s[1][1] == s[2][1]){
			cout << '1';
			if(finda(s[1][2]) == finda(s[2][2])){
				cout << '1';
				if(checkab(s[1][2], s[2][2])) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
