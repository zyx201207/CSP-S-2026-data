#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","R",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		if(s1[0]!=s2[0]&&s1[1]!=s2[1])cout<<"1000";
		else if(s1[3]<='B'&&s1[3]>='A'&&s2[3]<='B'&&s2[3]>='A')cout<<"1111";
		else if(s1[3]<='E'&&s1[3]>='C'&&s2[3]<='E'&&s2[3]>='C')
		{
			if(s1[3]=='D'||s2[3]=='D')cout<<"1111";
			else cout<<"1110";
		}
		else cout<<"1100";
	}
	return 0;
}
