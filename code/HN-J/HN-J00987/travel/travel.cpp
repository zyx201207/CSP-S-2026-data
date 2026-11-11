#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;string az,bz;
	cin >> a >> az >> b >> bz;
	if (a == b){
		cout << "1";
		if(az[0]+az[1] == bz[0]+bz[1]){
			cout << "1";
			if ((az[2]>='D' && bz[2] >='D') || (az[2]<='C' && bz[2] <='C')){
				cout << "1";
				if(abs(az[2]-bz[2]) == 1){
					cout << "1";
				}
				else {cout << "0";
				}
			}
			else {cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else {cout << "0000";} 
	return 0;
}
