#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

string c1, s1, c2, s2;
bool a1, a2, a3, a4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = (c1 == c2);
	a2 = a1&&(s1.substr(0,2) == s2.substr(0,2));
	bool t1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
	bool t2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	a3 = a1&&a2&&(!(t1^t2));
	bool t3=(s1[2]=='A'&&s2[2]=='B');
	bool t4=(s2[2]=='A'&&s1[2]=='B');
	bool t5=(s1[2]=='B'&&s2[2]=='C');
	bool t6=(s2[2]=='B'&&s1[2]=='C');
	bool t7=(s1[2]=='D'&&s2[2]=='F');
	bool t8=(s2[2]=='F'&&s1[2]=='D');
	a4 = a1&&a2&&a3&&(t3||t4||t5||t6||t7||t8);
	cout << a1 << a2 << a3 << a4;
	return 0;
}
