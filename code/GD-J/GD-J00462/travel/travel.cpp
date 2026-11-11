#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int x, y;
char x2, y2;
bool fl, fl2;
inline int tp(char ch){
	if (ch == 'A' || ch == 'B' || ch == 'C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)cout << "0", fl2 = 1;
	else cout << "1";
	fl = 1;
	for (auto i : s1){
		if (fl && i == '0')continue;
		else if (isdigit(i)){
			fl = 0;
			x = (x * 10) + (i - '0');
		}
		if (isalpha(i))x2 = i;
	}
	fl = 1;
	for (auto i : s2){
		if (fl && i == '0')continue;
		else if (isdigit(i)){
			fl = 0;
			y = (y * 10) + (i - '0');
		}
		if (isalpha(i))y2 = i;
	}
//	cout << "#" << x << " " << y << "\n";
//	cout << "@" << x2 << " " << y2 << "\n";
	if (fl2 || x ^ y)cout << "0", fl2 = 1;
	else cout << "1";
	if (fl2 || tp(x2) ^ tp(y2))cout << "0", fl2 = 1;
	else cout << "1";
	if (fl2 || abs(x2 - y2) > 1)cout << "0";
	else cout << "1";
	return 0;
} 
