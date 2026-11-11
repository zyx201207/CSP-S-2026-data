#include<bits/stdc++.h>
using namespace std;
string xc, rc;
string xz, rz;
bool is;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    cin >> xc >> xz >> rc >> rz;
    if (xc == rc) {
    	is = true;
    	cout << 1;
	}
    else {
    	cout << 0;
	}
    if (is && xz[0] == rz[0] && xz[1] == rz[1]) cout << 1;
    else {
    	is = false;
    	cout << 0;
	}
    if (is && (xz[2] == 'A' || xz[2] == 'B' || xz[2] == 'B') && (rz[2] == 'A' || rz[2] == 'B' || rz[2] == 'C') && xz != rz){
    	cout << 1;
	}else {
		if (is && (xz[2] == 'D' || xz[2] == 'F') && (rz[2] == 'D' || rz[2] == 'F') && xz != rz) {
			cout << 1;
		}else {
			is = false; 
			cout << 0;
		}
	}
	if (is && ((xz[2] == 'B' || rz[2] == 'B') || (xz[2] == 'D' || rz[2] == 'D'))){
		cout << 1;
	}else cout << 0;
	return 0;
} 
