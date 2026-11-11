#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int a,b,c,d;
char x,y;
int xx,yy;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	x = s1[2];
	y = s2[2];
	
	if(x == 'D' || x == 'F')xx = 2;
	else xx = 1;
	if(y == 'D' || y == 'F')yy = 2;
	else yy = 1;
	
	if(c1 == c2) a = 1;
	if(s1[0] == s2[0] && s1[1] == s2[1] && a == 1) b = 1;
	if(xx == yy && b == 1) c = 1;
	if((x+1 == y || x-1 == y) && c == 1) d = 1;
	
	cout << a << b << c << d;
	
	return 0;
}
