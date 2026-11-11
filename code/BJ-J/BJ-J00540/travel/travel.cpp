//T1
#include <bits/stdc++.h>
using namespace std;
//666第一眼还以为走错考场了...，总共题目疑似红黄黄青
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000\n";
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000\n";
	}
	else if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C'))
	{
		cout<<"1100\n";
	}
	else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
	{
		cout<<"1110\n";
	}
	else
	{
		cout<<"1111\n";
	}
	return 0;
}
