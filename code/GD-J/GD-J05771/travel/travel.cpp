#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string C, S, c, s;
bool f1 = 0, f2 = 1, f3 = 0, f4 = 0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> C >> S >> c >> s;
	if (C == c) f1 = 1;
	if (f1 == 0) {
		f2 = 0;
		f3 = 0;
		f4 = 0;
		cout << f1 << f2 << f3 << f4 <<endl;
		return 0;
	}
	for (int i = 0 ; i < 2 ; i++) {
		if(S[i] != s[i]) f2 = 0;
	}
	if (f2 == 0) {
		f3=0;
		f4=0;
		cout << f1 << f2 << f3 << f4 <<endl;
		return 0;
	}
	if ((S[2] < 'D' && s[2] < 'D')||(S[2] > 'C'&& s[2] > 'C')) f3=1;
	if (f3 == 0) {
		f4=0;
		cout << f1 << f2 << f3 << f4 <<endl;
		return 0;
	}
	if (S[2] == 'A'&& s[2] == 'B') f4 = 1;
	if (S[2] == 'B'&& s[2] == 'A') f4 = 1;
	if (S[2] == 'B'&& s[2] == 'C') f4 = 1;
	if (S[2] == 'C'&& s[2] == 'B') f4 = 1;
	if (S[2] == 'D'&& s[2] == 'F') f4 = 1;
	if (S[2] == 'F'&& s[2] == 'D') f4 = 1;
	if (f4 == 0) {
		cout << f1 << f2 << f3 << f4 <<endl;
		return 0;
	}
	cout << f1 << f2 << f3 << f4 <<endl;
	return 0;
}
