//贵阳市南明区李端棻中学 刘锦阳 GZ-J00260
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if(((int)s1[2] <= 67 && (int)s2[2] <= 67) || ((int)s1[2] > 67 && (int)s2[2] > 67)){
				cout << "1";
				int ans = (int)s1[2] - (int)s2[2];
				if(ans >= -1 && ans <= 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
}
