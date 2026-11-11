#include <bits/stdc++.h>
#define endl '\n'
#define fn "travel"
typedef long long ll;
using namespace std;
string s1, s2, s3, s4;
int main(){
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> s1 >> s2 >> s3 >> s4;
	int a = (s2[0] - '0') * 10 + (s2[1] - '0'), b = (s4[0] - '0') * 10 + (s4[1] - '0');
	if (s1 != s3) cout << "0000";
	else if(a != b) cout << 1000;
	else if((s2[2] <= 'C' && s4[2] >= 'D') || (s2[2] >= 'D' && s4[2] <= 'C')) cout << 1100;
	else if((s2[2] == 'A' && s4[2] == 'C') || (s2[2] == 'C' && s4[2] == 'A')) cout << 1110;
	else cout << 1111;
	return 0;
}
