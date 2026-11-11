#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
char a1,b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) 
	{
	cout << 1;
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout << 1;
	else cout << 0;
	if((s1[0]==s2[0] && s1[1]==s2[1]) &&((s1[2]>=65 && s1[2]<=67 && s2[2]>=65 && 
	s2[2]<=67) || (s1[2]>=68 && s1[2]<=70 && s2[2]>=68 && s2[2]<=70))) cout << 1;
	else cout << 0;
	if((s1[2]=='C' && s2[2]=='D' )||(s1[2]=='D' && s2[2]=='C' )) cout << 0;
    else if((s1[2]=='D' && s2[2]=='F' )||(s1[2]=='F' && s2[2]=='D' )) cout << 1;
	else if((s1[0]==s2[0] && s1[1]==s2[1]) && (abs(int(s1[2]-s2[2]))==1)) cout << 1;
	else cout << 0;
}
	else cout << "0000";
	

	return 0;
}
