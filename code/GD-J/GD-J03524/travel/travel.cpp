#include<bits/stdc++.h>
using namespace std;
bool x1,x2,x3,x4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)x1=1;
	if(x1==1 && s1[0]==s2[0] && s1[1]==s2[1])x2=1;
	if(x2==1)
	{
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))x3=1;
	}
	if(x3==1 && ((s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D')||abs(s1[2]-s2[2])==1))x4=1;
	cout<<x1<<x2<<x3<<x4;
	return 0;
}
