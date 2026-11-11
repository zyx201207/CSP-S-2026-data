#include <bits/stdc++.h>
using namespace std;

string s1, s2, t1, t2;

int nums, nums1, numt, numt1;

char nums2, numt2;

int stti(string s) {
	int num = 0;
	for (int i = 0; i < 2; i ++) {
		(num *= 10) += (s[i] - 48);
	}
	return num;
}

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> s1 >> s2 >> t1 >> t2;
	
	nums = stti(s1); nums1 = stti(s2);
	numt = stti(t1); numt1 = stti(t2);
	
	nums2 = s2[2]; 
	numt2 = t2[2];
	
	if (nums != numt) {
		cout << "0000" << endl;
		return 0;
	} else {
		if (nums1 != numt1) {
			cout << "1000" << endl;
		} else {
			bool flags = (nums2 >= 'A' && nums2 <= 'C');
			bool flagt = (numt2 >= 'A' && numt2 <= 'C');
			if (flags != flagt) {
				cout << "1100" << endl;
			} else {
				bool flag = (abs(nums2 - numt2) == 1);
				flag |= ((nums2 == 'D' && numt2 == 'F') || (nums2 == 'F' && numt2 == 'D'));
				if (!flag) {
					cout << "1110" << endl;
				} else {
					cout << "1111" << endl;
				}
			}
		}
	}
	
	
	return 0;
}
