#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen(".\\travel.in", "r", stdin);
	freopen(".\\travel.out", "w", stdout);
	
	int c1,c2;
	string s1,s2;
	
	cin>>c1>>s1>>c2>>s2;
	
	cout << int(c1==c2);
	
	int flag = int(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2);
	cout << flag;
	
	flag = flag&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'));
	cout << flag;
	cout << (flag&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1));
	
	return 0;
}
