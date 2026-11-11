#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2; int n1, n2, n3, n4; bool b[4] = {0}; char lb1, lb2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int len1 = c1.size();
	int len2 = c2.size();
	n1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	n2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	n3 = (s1[0] - '0') * 10 + (s1[1] - '0');
	n4 = (s2[0] - '0') * 10 + (s2[1] - '0');
	lb1 = s1[2]; lb2 = s2[2];
	if(n1 == n2 && (n1 >= 2 && n1 <= 15 || n1 == 17)) {
		b[0] = 1;
		if(n3 == n4) {
			b[1] = 1;
			if((lb1 >= 'A' && lb1 <= 'C') && (lb2 >= 'A' && lb2 <= 'C')) {
				b[2] = 1;
				if(lb1 == (char)(lb2 + 1) || lb1 == (char)(lb2 - 1)) b[3] = 1;
			} else if((lb1 >= 'D' && lb1 <= 'E') && (lb2 >= 'D' && lb2 <= 'E')) {
				b[2] = b[3] = 1;
			}
		}
	}
	cout << b[0] << b[1] << b[2] << b[3];
	return 0; 
}

