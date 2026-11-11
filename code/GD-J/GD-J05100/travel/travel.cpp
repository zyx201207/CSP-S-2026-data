#include <bits/stdc++.h>
using namespace std;
string rtrain, rseat, xtrain, xseat;
int main (){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rtrain >> rseat >> xtrain >> xseat;
	// 同车厢 
	if (rtrain == xtrain){
		cout << "1";
	} else {
		cout << "0";
	}
	// 同排 
	if (rseat[0] == xseat[0] && rseat[1] == xseat[1] && rtrain == xtrain){
		cout << "1";
	} else {
		cout << "0";
	}
	// 同排，同一侧 
	if (rseat[0] == xseat[0] && rseat[1] == xseat[1] && rtrain == xtrain){
		if ((rseat[2] == 'A' && xseat[2] == 'B') || (rseat[2] == 'A' && xseat[2] == 'C') || (rseat[2] == 'B' && xseat[2] == 'A') || (rseat[2] == 'B' && xseat[2] == 'C') || (rseat[2] == 'C' && xseat[2] == 'A') || (rseat[2] == 'C' && xseat[2] == 'B') || (rseat[2] == 'D' && xseat[2] == 'F') || (rseat[2] == 'F' && xseat[2] == 'D'))
			cout << "1";
		else
			cout << "0";
	} else {
		cout << "0";
	}
	// 相邻
	if (rseat[0] == xseat[0] && rseat[1] == xseat[1] && rtrain == xtrain){
		if ((rseat[2] == 'A' && xseat[2] == 'B') || (rseat[2] == 'B' && xseat[2] == 'A') || (rseat[2] == 'C' && xseat[2] == 'B') || (rseat[2] == 'B' && xseat[2] == 'C') || (rseat[2] == 'D' && xseat[2] == 'F') || (rseat[2] == 'F' && xseat[2] == 'D'))
			cout << "1";
		else
			cout << "0"; 
	} else {
		cout << "0";
	}
	return 0;
}
