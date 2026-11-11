#include <iostream>
#include <cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool is[4] = {false};
	is[0] = (c1[0] == c2[0] && c1[1] == c2[1]);
	is[1] = (is[0] && s1[0] == s2[0] && s1[1] == s2[1]);
	is[2] = (is[1] && (s1[2] != s2[2] && (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E')))));
	is[3] = (is[2] && abs(s1[2] - s2[2]) == 1);
	cout << is[0] << is[1] << is[2] << is[3] << endl;
	return 0;
}
