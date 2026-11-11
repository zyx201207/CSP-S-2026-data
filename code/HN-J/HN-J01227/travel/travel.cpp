#include <bits/stdc++.h>
using namespace std;
//#define ll long long
//const ll MAXN = 5;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	map<char, int> tiket;
	tiket['A'] = 1;
	tiket['B'] = 2;
	tiket['C'] = 3;
	tiket['D'] = 7;
	tiket['F'] = 8;
	int c1 = 0, c2 = 0;
	bool TP = true, TCX = false, TC = false, XL = false;
	string s1 = "", s2 = "";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) TCX = true;
	
	for (int i = 0; i <= 1; i++) 
		if(s1[i] != s2[i] || !TCX) TP = false;
	if (((abs(tiket[s1[2]] - tiket[s2[2]])) <= 2) && TCX && TP) TC = true;
	if ((abs(tiket[s1[2]] - tiket[s2[2]]) == 1) && TCX && TP && TC) XL = true;
	cout << TCX ? 1 : 0;
	cout << TP ? 1 : 0;
	cout << TC ? 1 : 0;
	cout << XL ? 1 : 0;
	return 0;
}
