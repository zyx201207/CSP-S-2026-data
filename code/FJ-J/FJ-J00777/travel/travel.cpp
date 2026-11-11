#include<bits/stdc++.h>
#define long long ll
using namespace std;

string c1, s1, c2, s2;

void solve()
{
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) cout << "0000";
	else {
		cout << '1';
		int a = 10 * (s1[0] - '0') + (s1[1] - '0');
		char A = s1[2];
		int b = 10 * (s2[0] - '0') + (s2[1] - '0');
		char B = s2[2];
		if(a != b) cout << "000";
		else {
			cout << '1';
			if(('A' <= A && A <= 'C' && 'A' <= B && B <= 'C') || ('D' <= A && A <= 'F' && 'D' <= B && B <= 'F')) {
				cout << '1';
				if(abs(A-B) == 1 || (A =='D' && B=='F') || (A == 'F' && B == 'D')) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

