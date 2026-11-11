//GZ-J00026 贵阳市白云区华师一学校 杨泊静 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,c = "",s = "",q = "",p = "";
	cin >> c1 >> s1 >> c2 >> s2;
	c = s1[0]+s1[1];
	s = s2[0]+s2[1];
	q = s1[2];
	p = s2[2];
	if(c1 != c2) cout << "0000";
	else if(c != s) cout << 1000;
	else if((q == "D" && p == "F") || (q == "F" && p == "D") || (q == "A" && p == "B") || (q == "B" && p == "A") || (q == "B" && p == "C") || (q == "C" && p == "B")) cout << 1111;
	else if((q == "D" && p == "F") || (q == "F" && p == "D") || (q == "A" && p == "B") || (q == "B" && p == "A") || (q == "B" && p == "C") || (q == "C" && p == "B") || (q == "A" && p == "C") || (q == "C" && p == "A")) cout << 1110;
	else cout << 1100;
	return 0;
}
