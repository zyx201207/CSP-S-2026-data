#include <bits/stdc++.h>
using namespace std;
string c2, s2;
int s1, c1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> c2 >> s1 >> s2;
	int c3 = (char)c2[0] + (char)c2[1] - '0' - '0', s3 = (char)s2[0] + (char)s2[1] - '0' - '0', c4 = (char)c2[2], s4 = (char)s2[2]; 
	if (c1 == s1){
		if (c3 == s3){
			if ((c4 <= 'C' && s4 <= 'C') || (c4 > 'C' && s4 > 'C')){
				if (abs(c4 - s4) == 1)cout << 1111;
				else if (max(c4, s4) == 'F') cout << 1111;
				else cout << 1110;
			}
			else cout << 1100;
		}
		else cout << 1000;
	}
	else cout << 0000;
	return 0;
} 
