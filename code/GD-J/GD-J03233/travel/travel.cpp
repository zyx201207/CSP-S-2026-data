#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string c1,s1,c2,s2;
int flag[1005];

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	flag[int('A')] = 1;
	flag[int('B')] = 1;
	flag[int('C')] = 1;
	flag[int('D')] = 2;
	flag[int('F')] = 2;
	if (c1 == c2){
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if (flag[int(s1[2])] == flag[int(s2[2])]){
				cout << "1";
				if ( abs(int(s1[2])-int(s2[2])) == 1){cout << "1";}
				else{cout << "0";}
			}
			else{cout << "00";}
		}
		else{cout << "000";}
	}
	else{cout << "0000";}
	return 0;
}
