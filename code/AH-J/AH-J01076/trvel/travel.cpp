#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	//
	string c1,s1,c2,s2;
	string p1,p2,z1,z2;
	//
	cin>>c1>>s1>>c2>>s2;
	//
	p1+=s1[0];p1+=s1[1];
	p2+=s2[0];p2+=s2[1];
	z1+=s1[2];z2+=s2[2];
	//
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(p1!=p2)
	{
		cout<<"1000";
		return 0;
	}
	if(z1<='C'&&z2>='D'||z1>='D'&&z2<='C')
	{
		cout<<"1100";
		return 0;
	}
	if(z1=='C'&&z2=='A'||z1=='A'&&z2=='C')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
		
	return 0;

}
