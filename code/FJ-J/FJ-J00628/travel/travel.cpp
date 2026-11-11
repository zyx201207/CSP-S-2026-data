#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int ac, bc, az, bz;
	char ar, br;
	cin >> ac >> az >> ar >> bc >> bz >> br;
	
	if(ac == bc){
		cout << 1;
		if(az == bz){
			cout << 1;
			if((ar <= 'C' && br <= 'C') || (ar >= 'D' && br >= 'D')){
				cout << 1;
				if(ar >= 'D' || br >= 'D'){
					cout << 1;
				}else if(abs(ar - br) == 1){
					cout << 1;
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}
	else cout << "0000";
	
	return 0;
}
// 02 01A 02 01B
