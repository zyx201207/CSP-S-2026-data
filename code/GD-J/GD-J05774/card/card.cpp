#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a, b;
	string aa, bb;
	bool t = true;
	cin >> a >> aa >> b >> bb;
	
	if (a == b) {
		cout << 1;
	} else {
		cout << 0;
		t = false;
	}
	
	if (t) {
		string aa1 = "", bb1 = "";
		aa1 += aa[0];
		aa1 += aa[1];
		bb1 += bb[0];
		bb1 += bb[1];
		if (aa1 == bb1) {
			cout << 1;
		} else {
			cout << 0;
			t = false;
		}
	} else {
		cout << 0;
		t = false;
	}
	
	char aaa, bbb;
	aaa = aa[2];
	bbb = bb[2];
	int tt = 0;
	if (t) {
//		cout << aaa << " " << bbb;
		if ((aaa == 'A') && ((bbb == 'B') || (bbb == 'C'))) {
			tt = 1;
			cout << 1;
		}
		if ((aaa == 'D') && (bbb == 'F')) {
			tt = 2;
			cout << 1;
		}
		if ((bbb == 'A') && ((aaa == 'B') || (aaa == 'C'))) {
			tt = 1;
			cout << 1;
		}
		if ((bbb == 'D') && (aaa == 'F')) {
			tt = 2;
			cout << 1;
		}
		if (tt == 0) {
			cout << 0;
			t = false;
		}
	} else {
		cout << 0;
		t = false;
	}
	
//	cout << "t:" << t << "      " << endl; 
	if (t) {
		if (tt == 2) cout << 1;
		else if ((aaa == 'A') && (bbb == 'B')) cout << 1;
		else if ((aaa == 'B') && (bbb == 'C')) cout << 1;
		else if ((bbb == 'A') && (aaa == 'B')) cout << 1;
		else if ((bbb == 'B') && (aaa == 'C')) cout << 1;
		else cout << 0;
	} else {
		cout << 0;
		t = false;
	}
	
	return 0;
}

// 02 01A 03 01A
