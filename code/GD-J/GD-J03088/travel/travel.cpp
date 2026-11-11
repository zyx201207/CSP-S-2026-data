#include<iostream>
using namespace std;
int main()
{
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;
	if(c1==c2)
	a=1;
	if(a==1&s1[0]==s2[0]&s1[1]==s2[1])
	b=1;
	if(s1[2]=='A'|s1[2]=='B'|s1[2]=='C'&s2[2]=='A'|s2[2]=='B'|s2[2]=='C')
	if(b==1)
	c=1;
	if(s1[2]=='D'|s1[2]=='F'&s2[2]=='D'|s2[2]=='f')
	if(b==1)
	c=1;
	if(s1[2]-s2[2]==1|s1[2]-s2[2]==-1)
	if(c==1)
	d=1;
	cout<<a<<b<<c<<d<<endl;
	
	return 0;
}
