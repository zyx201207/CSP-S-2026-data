#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char Rz[10], Xz[10];
	int Rx, Xx;
	cin >> Rx >> Rz >> Xx >> Xz;
	if(Rx == Xx) cout << 1;
	else cout << 0;
	if(Rz[0] == Xz[0] && Rz[1] == Xz[1] && Rx == Xx) cout << 1;
	else cout << 0;
	if(Rz[2] >= 68 && Xz[2] >= 68 && Rz[0] == Xz[0] && Rz[1] == Xz[1] && Rx == Xx) cout << "11";
	else if(Rz[2] < 68 && Xz[2] < 68 && Rz[0] == Xz[0] && Rz[1] == Xz[1] && Rx == Xx){
		cout << 1;
		if(abs(Rz[2] - Xz[2]) == 1)
			cout << 1;
		else cout << 0;
	}
	else cout << "00";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
