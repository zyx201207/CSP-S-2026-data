#include <iostream>
using namespace std;
string a1,a2,b1,b2,a3,b3,a4,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 == b1){
		cout << '1';
		a3 = a2[0] + a2[1];
		b3 = b2[0] + b2[1];
		if(a3 == b3){
			cout << '1';
			if(a2[2] <= 'C' && a2[2] >= 'A') a4 = '1';
			else if(a2[2] >= 'D' && a2[2] <= 'F') a4 = '2';
			if(b2[2] <= 'C' && b2[2] >= 'A') b4 = '1';
			else if(b2[2] >= 'D' && b2[2] <= 'F') b4 = '2';
			if(a4 == b4){
				cout << '1';
				if(b2[2] + 1 == a2[2] || b2[2] - 1 == a2[2]) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else{
		cout << "0000";	
	}
	return 0;
} 
