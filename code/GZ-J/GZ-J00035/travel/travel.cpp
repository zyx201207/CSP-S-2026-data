//GZ-J00035  都匀市第三中学  潘彦旭 
#include <iostream> 
#include <cmath> 
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main()
{ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	bool flag=1,flag1=0;
	for(int i=0;i<=c1.length()-1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<0;
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<1;
	}
	if(((s2[2]<='C'&&s1[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&flag)
	{
		cout<<1;
		flag1=1;
	}
	else
		cout<<0;
	if(flag&&flag1)
	{
		a=s1[2]-'0';
		b=s2[2]-'0';
		if(abs(a-b)>1)
			cout<<0;
		else if(abs(a-b)>0&&abs(a-b)<=1)
			cout<<1;
	}
	else
		cout<<0;
	return 0;
}
