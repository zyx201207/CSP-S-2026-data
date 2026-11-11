#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string z1="",z2="";
	char z3,z4;
	z1=s1[0]+s1[1];
	z2=s2[0]+s2[1];
	z3=s1[2];
	z4=s2[2];
	bool b=0,x=0;
	if((z3>='A'&&z3<='C'&&z4>='A'&&z4<='C')||(z3>='D'&&z3<='F'&&z4>='D'&&z4<='F')) b=1;
	int p=(int)z3;
	int q=(int)z4;
	if(abs(p-q)==1&&b==1) x=1;

	
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&z1==z2) cout<<1;
	else cout<<0;
	if(c1==c2&&z1==z2&&b==1) cout<<1;
	else cout<<0;
	if(c1==c2&&z1==z2&&b==1&&x==1) cout<<1;
	else cout<<0;
	return 0;
 } 
