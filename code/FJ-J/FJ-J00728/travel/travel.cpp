#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		int x1 = (s1[0]-'0')*10 + s1[1]-'0', x2 = (s2[0]-'0')*10 + s2[1]-'0';
		if(x1 == x2){
			cout << 1;
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
				cout << 1;
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'E') || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s2[2] == 'D' && s1[2] == 'E')){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
