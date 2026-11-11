#include <iostream>
#include <cstdio> 
#include <string>
#include <cmath>
using namespace std;

string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int p1 = stoi(s1.substr(0,2)),p2 = stoi(s2.substr(0,2));
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && p1 == p2) cout << 1;
	else cout << 0;
	if (c1 == c2 && p1 == p2 && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D')) cout << 1;
	else cout << 0;
	if (c1 == c2 && p1 == p2 && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') && abs(s1[2] - s2[2]) == 1) cout << 1;
	else cout << 0;
	return 0;
}
