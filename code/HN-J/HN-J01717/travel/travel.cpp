#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,cb;
	int sa,sb;
	char x,y;
	cin >> ca >> sa >> x >> cb >> sb >> y;
	if(ca == cb){
		cout << "1";
		if(sa == sb){
			cout << "1";
			if((x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C') || (x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F')){
				cout << "1";
				if(x == y-1 || x == y+1 || (x == 'F' && y == 'D') || (x == 'D' || y == 'F')){
					cout << "1";
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
