#include <bits/stdc++.h>

using namespace std;

int x1,y1,x2,y2;
char z1,z2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	if(x1 != x2){
		cout << "0000";
	}
	else{
		cout << 1;
		if(y1 != y2){
			cout << "000";
		}
		else{
			cout << 1;
			if(z1 < 'D' && z2 <'D'){
				cout << 1;
				if(abs(z1-z2) > 1){
					cout << 0;
				}
				else{
					cout << 1;
				}
			}
			else{
				if(z1 > 'C' && z2 >'C'){
					cout << "11";
				}
				else{
					cout << "00";
				}
			}
		}
	}
}
