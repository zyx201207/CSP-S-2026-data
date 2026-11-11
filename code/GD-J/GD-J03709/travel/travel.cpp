#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel,out","w",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	int f[5]={};
	if(c1[0]==c2[0]&&c1[1]==c2[1]) f[0]=1;
	else
	{
		cout<<"0000\n";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) f[1]=1;
	else
	{
		cout<<"1000\n";
		return 0;
	}
	if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2)) f[2]=1;
	else
	{
		cout<<"1100\n";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')
	||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')
	||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) f[3]=1;
	else
	{
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
}
