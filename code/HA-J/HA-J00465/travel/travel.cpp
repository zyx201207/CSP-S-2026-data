#include <bits/stdc++.h>
using namespace std;


int a;
int b;
char a1[3];
char b1[3];
char ans;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	cin >> a >> a1[0] >> a1[1] >> a1[2];
	cin >> b >> b1[0] >> b1[1] >> b1[2];

	
	if (a == b){
		if (a1[0] == b1[0] && a1[1] == b1[1]){
			if ((a1[2] == 'A' || a1[2] == 'B' || a1[2] == 'C') && (b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C')){
				if ((a1[2] == 'A' && b1[2] == 'B') || (a1[2] == 'B' && b1[2] == 'C') || (a1[2] == 'D' && b1[2] == 'F') || (b1[2] == 'A' && a1[2] == 'B') || (b1[2] == 'B' && a1[2] == 'C') || (b1[2] == 'D' && a1[2] == 'F')){
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				if ((a1[2] == 'D' || a1[2] == 'F' ) &&(b1[2] == 'F' || b1[2] == 'D')){
					if ((a1[2] == 'A' && b1[2] == 'B') || (a1[2] == 'B' && b1[2] == 'C') || (a1[2] == 'D' && b1[2] == 'F') || (b1[2] == 'A' && a1[2] == 'B') || (b1[2] == 'B' && a1[2] == 'C') || (b1[2] == 'D' && a1[2] == 'F')){
					cout << "1111";
				} else {
					cout << "1110";
				}
				} else {
					cout << "1100";
				}
			}
		} else {
			cout << "1000";
		} 
	
	} else {
		cout << "0000";
	}
	return 0;
}

