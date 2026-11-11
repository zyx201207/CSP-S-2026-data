#include <iostream>
using namespace std;
int r, x;
string rr, xx;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> rr >> x >> xx;
	if(r == x) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if(rr[0] == xx[0] && rr[1] == xx[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	if((rr[2] >= 'A' && rr[2] <= 'C' && xx[2] >= 'A' && xx[2] <= 'C') ||
	((rr[2] == 'D' || rr[2] == 'F') && (xx[2] == 'D' || xx[2] == 'F'))) cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if(((int)xx[2] - rr[2] == 1 || (int)rr[2] - xx[2] == 1) || (xx[2] == 'D' && rr[2] == 'F') || (xx[2] == 'F' && rr[2] == 'D')) cout << "1";
	else cout << "0";
	return 0;
}
