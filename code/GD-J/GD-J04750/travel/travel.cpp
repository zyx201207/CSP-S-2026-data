#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,b1,c2,b2;
	cin >> c1 >> b1 >> c2 >> b2;
	if(c1 == c2){
		cout << 1;
		if(b1[0] == b2[0] && b1[1] == b2[1]){
			cout << 1;
			if(b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C'){
				if(b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C'){
					cout << 1;
					if(b1[2] == b2[2]+1 || b1[2]+1 == b2[2]){
						cout << 1;
						return 0;
					}
					cout << 0;
					return 0;
				}
			}
			else if(b1[2] == 'D' || b1[2] == 'F'){
				if(b2[2] == 'D' || b2[2] == 'F'){
					cout << 11;
					return 0;
				}
			}
			cout << "00";
			return 0;
		}
		cout << "000";
		return 0;
	}
	cout << "0000";
	return 0;
}
