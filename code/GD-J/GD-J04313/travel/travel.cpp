#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = (c1==c2);
	bool b = (s1[0]==s2[0]&&s1[1]==s2[1]);
	bool c;
	if (s1[2]=='A') c = (s2[2]=='B'||s2[2]=='C');
	else if (s1[2]=='B') c = (s2[2]=='A'||s2[2]=='C');
	else if (s1[2]=='C') c = (s2[2]=='B'||s2[2]=='A');
	else if (s1[2]=='D') c = (s2[2]=='F');
	else c = (s2[2]=='D');
	
	bool d ;
	if (s1[2]=='A') d = (s2[2]=='B');
	else if (s1[2]=='B') d = (s2[2]=='A'||s2[2]=='C');
	else if (s1[2]=='C') d = (s2[2]=='B');
	else if (s1[2]=='D') d = (s2[2]=='F');
	else d=s2[2]=='D';
	if (a)cout << 1;
	else cout << 0;
	if (a&&b)cout << 1;
	else cout << 0;
	if (a&&b&&c)cout << 1;
	else cout << 0;
	if ((a&&b)&&(c&&d)) cout << 1;
	else cout << 0;
	return 0;
}
