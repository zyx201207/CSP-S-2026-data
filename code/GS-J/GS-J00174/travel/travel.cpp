#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string ca , za , cb , zb;
	cin >> ca >> za >> cb >> zb;
	
	if(ca != "01" && ca != "16" && cb != "01" && cb != "16" && ca == cb){
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if(za[0] == zb[0] && za[1] == zb[1]){
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	
	if(za[2] == 'A' || za[2] == 'B' || za[2] == 'C'){
		if(zb[2] == 'A' || zb[2] == 'B' || zb[2] == 'C'){
			cout << "1";
			if(za[2] == 'A'){
				if(zb[2] == 'B'){
					cout << "1";
					return 0;
				}
			}	
			if(za[2] == 'B'){
				if(zb[2] == 'A'){
					cout << "1";
					return 0;
				}
				if(zb[2] == 'C'){
					cout << "1";
					return 0;
				}
			}
			if(za[2] == 'C'){
				if(zb[2] == 'B'){
					cout << "1";
					return 0;
				}
			}
			cout << "0";
			return 0;
		} else {
			cout << "00";
			return 0;
		}
	} 
	
	if(za[2] == 'D' || za[2] == 'F'){
		if(zb[2] == 'D' || zb[2] == 'F'){
			cout << "11";
			return 0;
		} 
	} else {
		cout << "00";
		return 0;
	}		
	return 0;
}
