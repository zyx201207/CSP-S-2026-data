#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
int c1, c2;
string s1, s2;
string calc1()
{
	if ((s1.substr(0, 2) != s2.substr(0, 2)))    return "0";
	if (s1.back() == 'D' && s2.back() != 'D')    return "0";
	if (s1.back() == 'F' && s2.back() != 'D')    return "0";
	if (s1.back() == 'A' && (s2.back() != 'B' && s2.back() != 'C'))    return "0";
	if (s1.back() == 'C' && (s2.back() != 'B' && s2.back() != 'A'))    return "0";
	if (s1.back() == 'B' && (s2.back() != 'A' && s2.back() != 'C'))    return "0";
	return "1";
}


string calc2()
{
	if ((s1.substr(0, 2) != s2.substr(0, 2)))    return "0";
	if (s1.back() == 'D' && s2.back() != 'F')    return "0";
	if (s1.back() == 'F' && s2.back() != 'D')    return "0";
	if (s1.back() == 'A' && s2.back() != 'B')    return "0";
	if (s1.back() == 'C' && s2.back() != 'B')    return "0";
	if (s1.back() == 'B' && (s2.back() != 'A' && s2.back() != 'C'))    return "0";
//	cout << s1.back() << endl << s2.back() << endl;
	return "1"; 
}
signed main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << ((c1 == c2) ? "1" : "0") << ((c1 == c2) && (s1.substr(0, 2) == s2.substr(0, 2)) ? "1" : "0") << calc1() << calc2();
	return 0;
}

