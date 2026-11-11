#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1,flag2,flag3,flag4;

int main()
{
	freopen("travel.in",".r",stdin);
	freopen("travel.out",".w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		flag1=1;
	
	string col1=s1.substr(0,2),col2=s2.substr(0,2);
	if(col1==col2&&flag1)
		flag2=1;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')	
	{
		if(s2[2]=='D'||s2[2]=='F')
			flag3=flag3;
		else if(flag2)
			flag3=1; 
	}
//	cout<<ans<<flag1<<flag2<<flag3;
	if(flag1&&flag2&&flag3)
	{
		if(char(s1[2]+1)==s2[2] || char(s2[2]+1)==s1[2])
			flag4=1;
	}
	cout<<flag1<<flag2<<flag3<<flag4; 
	return 0;
}
