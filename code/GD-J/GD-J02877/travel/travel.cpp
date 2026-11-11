#include <bits/stdc++.h>
using namespace std;

bool samecar(int a, int b){
	if(a == b) return true;
	return false;
}

bool sameline(string a, string b){
	if(a[0] == b[0] && a[1] == b[1]) return true;
	return false;
}

bool sameside(string a, string b){
	if(a[2] == 'A' && b[2] == 'B') return true;
	if(a[2] == 'A' && b[2] == 'C') return true;
	if(a[2] == 'B' && b[2] == 'A') return true;
	if(a[2] == 'B' && b[2] == 'C') return true;
	if(a[2] == 'C' && b[2] == 'A') return true;
	if(a[2] == 'C' && b[2] == 'B') return true;
	if(a[2] == 'D' && b[2] == 'F') return true;
	if(a[2] == 'F' && b[2] == 'D') return true;
	return false;
}

bool beside(string a, string b){
	if(a[2] == 'A' && b[2] == 'B') return true;
	if(a[2] == 'B' && b[2] == 'A') return true;
	if(a[2] == 'B' && b[2] == 'C') return true;
	if(a[2] == 'C' && b[2] == 'B') return true;
	if(a[2] == 'D' && b[2] == 'F') return true;
	if(a[2] == 'F' && b[2] == 'D') return true;
	return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int rcar, xcar;
	string rseat, xseat;
	cin >> rcar >> rseat >> xcar >> xseat;
	bool q1, q2, q3, q4;
	q1 = samecar(rcar, xcar);
	if(q1) q2 = sameline(rseat, xseat);
	else q2 = false;
	if(q2) q3 = sameside(rseat, xseat);
	else q3 = false;
	if(q3) q4 = beside(rseat, xseat);
	else q4 = false;
	cout << q1 << q2 << q3 << q4 << endl;
	return 0;
}
