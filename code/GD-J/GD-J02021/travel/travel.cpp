#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int num1=(s1[0]-'0')*10+(s1[1]-'0'),num2=(s2[0]-'0')*10+(s2[1]-'0');
	int side1,side2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')side1=1;
	else side1=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')side2=1;
	else side2=2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&num1==num2)cout<<1;
	else cout<<0;
	if(c1==c2&&num1==num2&&side1==side2)cout<<1;
	else cout<<0;
	if(c1==c2&&num1==num2&&side1==side2&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
