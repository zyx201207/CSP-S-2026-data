//兰玉昊 GZ-J00057 观山湖中学
#include<bits/stdc++.h>
using namespace std;

int a, b;
string s1, s2;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> s1 >> b >> s2;
	if(a != b){
		cout << "0000";
	}else{
		cout << 1;
		if(s1[0] != s2[0] || s1[1] != s2[1]){
			cout << "000";
		}else{
			cout << 1;
			if(((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'D' && s2[2] <= 'F')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'A' && s2[2] >= 'C'))){
				cout << "00";
			}else{
				cout << 1;
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
					cout << 1;
				}else{
					cout << 0;
				}
			}
		}
	}
	return 0;
}
