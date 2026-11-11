#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3="",s4="";
char s5,s6;
int fl = 0,f = 0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	s5 = s1[2];
	s6 = s2[2];
	s3 = s1[0] + s1[1];
	s4 = s2[0] + s2[1];
	if(c1 == c2) 
	{
		cout << 1;
		fl = 1;
	}
	else cout << 0;
	if(fl && (s3 == s4))
	{
		cout << 1;
		f = 1;
	} 
	else cout << 0;
	if(fl && f == 1 && s5 <= 'C' && s6 <= 'C' || s5 > 'C' && s6 > 'C') cout << 1;
	else cout << 0;
	bool a = (s5 == 'A' && s6 == 'B'),b = (s5 == 'B' && s6 == 'C'),c = (s5 == 'D' && s6 == 'E');
	bool d = (s5 == 'B' && s6 == 'A'),e = (s5 == 'C' && s6 == 'B'),F = (s5 == 'E' && s6 == 'D');
	if(fl && f == 1 && (a || b || c || d || e || F) ) cout << 1;
	else cout << 0;
	return 0;
}
