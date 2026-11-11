#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int cx1, zw1, id1, cx2, zw2, id2;
	cx1 = (c1[0]-'0')*10 + (c1[1]-'0');
	cx2 = (c2[0]-'0')*10 + (c2[1]-'0');
	zw1 = (s1[0]-'0')*10 + (s1[1]-'0');
	zw2 = (s2[0]-'0')*10 + (s2[1]-'0');
	id1 = s1[2]-'A'+1;
	id2 = s2[2]-'A'+1;
	if (cx1 == cx2){
		cout << 1;
		if (zw1 == zw2){
			cout << 1;
			if (id1<=3&&id2<=3||id1>=4&&id2>=4){
				cout << 1;
				if (abs(id1-id2) == 1)cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
		
	}
	else cout << "0000";
	return 0;
} 
