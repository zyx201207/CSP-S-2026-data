#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, cc, ss;
	cin >> c >> s >> cc >> ss;
	bool f = false, ff = false, fff = false;
	bool ffff = false;
	if(c == cc) f = true;
	if(f && s[0] + s[1] == ss[0] + ss[1]) ff = true;
	if(ff && (s[2] == 'F' && ss[2] == 'D' || s[2] == 'D' && ss[2] == 'F')){
		fff = true;
	}
	if(ff && (s[2] <= 'C' && ss[2] <= 'C' && s[2] >= 'A' && ss[2] >= 'A')){
		fff = true;
	}
	if(fff && (s[2] - ss[2] == 1 || s[2] - ss[2] == -1)) ffff = true;
	if(fff && (s[2] == 'D' && ss[2] == 'F' || s[2] == 'F' && ss[2] == 'D')){
		ffff = true;
	}
	if(f) cout << 1;
	else cout << 0;
	if(ff) cout << 1;
	else cout << 0;
	if(fff) cout << 1;
	else cout << 0;
	if(ffff) cout << 1;
	else cout << 0;
	return 0;
}
