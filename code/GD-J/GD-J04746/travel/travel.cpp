#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool b=0;
	cin>>c1>>s1>>c2>>s2;
	if (c1[0]==c2[0]&&c1[1]==c2[1])  cout<<1;
	else  cout<<0;
	if (s1[0]==s2[0]&&s1[1]==s2[1])  cout<<1;
	else  cout<<0;
	if ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
	{
		cout<<1;
		b=1;
	}
	else  cout<<0;
	if (abs(s1[2]-s2[2])==1&&b)  cout<<1;
	else  cout<<0;
	return 0;
}
