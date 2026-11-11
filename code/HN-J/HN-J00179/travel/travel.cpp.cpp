#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a1 = s1[2];
	char a2 = s2[2];
	if(c1==c2&&a1>'C'&&a2>'C'&&s1[1]==s2[1]&&s1[0]==s2[0]) cout<<1111;
	else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if(a1=='A'&&a2=='C'||a1=='C'&&a2=='A') cout<<1110;
		else if(a1<='C'&&a2>='D'||a2<='C'&&a1>='D') cout<<1100;
		else cout<<1111;
	}
	else if(c1==c2)
	{
		cout<<1000;
	}
	else cout<<"0000";
	return 0;
}
