#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << 1;
	else cout << 0;
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout << 1;
	else cout << 0;
	int tmp1,tmp2;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') tmp1=1;
	else tmp1=2;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') tmp2=1;
	else tmp2=2;
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && tmp1==tmp2) cout << 1;
	else cout << 0;
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && tmp1==2 && tmp2==2) cout << 1;
	else if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && tmp1==1 && tmp2==1)
	{
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s2[2]=='A' && s1[2]=='B') || (s2[2]=='B' && s1[2]=='C')) cout << 1;
		else
		{
			cout << 0;
			return 0;
		}
	}
	else cout << 0;
	return 0;
}
