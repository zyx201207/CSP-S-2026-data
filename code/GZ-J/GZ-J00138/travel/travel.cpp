//GZ-J00138 遵义航天实验中学 涂宗睿  
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n1[]=s1,n2[]=s2;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(n1[0]==n2[0] && n1[1]==n2[1])
		cout<<"1";
	else
		cout<<"0";
	if(n1[2]==n2[2])
		cout<<"1";
	else
		cout<<"0";
	if(n1[3]==n2[3]-1 || n1[3]="F"-"2" && n2[3]=="F" )
	{
		cout<<"1";
		if(n1[3]=="C" && n2[3]=="D")
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
