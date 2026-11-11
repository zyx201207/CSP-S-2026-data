#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int rc, lc;
	char rs1, rs2, rs3, ls1, ls2, ls3;
	cin >> rc >> rs1 >> rs2 >> rs3 >> lc >> ls1 >> ls2 >> ls3;
	if(rc == lc) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(rs1 == ls1 && rs2 == ls2) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	int rr3 = rs3-'A', ll3 = ls3-'A';
	if((rr3 <= 2 && ll3 <= 2) || (rr3 >= 3 && ll3 >= 3)) cout << 1;
	else{
		cout << "00";
		return 0;
	}
	if(rr3 <= 2){
		if(abs(rr3-ll3) == 1) cout << 1;
		else{
			cout << 0;
			return 0;
		}
	}else{
		if(abs(rr3-ll3) == 2) cout << 1;
		else{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
