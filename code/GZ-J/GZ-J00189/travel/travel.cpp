#include<bits/stdc++.h>
using namespace std;
int main()
{
	//贵阳市第十九中学 刘臣耘 GZ-J00189
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(c1==c2) a=1;
	else a=0;
	
	if(c1==c2&&s1%10/10==s2%10/10) b=1;
	else b=0;
	
	if(c1==c2&&s1%10/10==s2%10/10) 
	{
		if((s1%10=='A'||'B'||'C'&&s2%10=='A'||'B'||'C')||(s1%10=='D'||'F'&&s2%10=='D'||'F')) c=1;
	}
	else c=0;
	
	if(s1/5==s2/5||s1/18==s2/18)
	{	
		if(s1/5==s2/5)
		{
			if(s1%5-s2%5==1||s2%5-s1%5==1) d=1;
			else d=0;
		}
		else if(s1/18==s2/18)
		{
			if(s1%18-s2%18==1||s2%18-s1%18==1) d=1;
			else d=0;
		}	
	}
	cout<<a<<" "<<b<<" "<<c<<""<<d;
	return 0; 
}
