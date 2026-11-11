#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
string c1 , s1 , c2 , s2;
bool t = true;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2 && t) cout << 1;
	else {t = false;cout << 0;}
	if(t && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {t = false;cout << 0;}
	if(t && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))) cout << 1;
	else {t = false;cout << 0;}
	if(t && abs(s1[2] - s2[2]) == 1) cout << 1;
	else {t = false;cout << 0;}
	return 0;
}
