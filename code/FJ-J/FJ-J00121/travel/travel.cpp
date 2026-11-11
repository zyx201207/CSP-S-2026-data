#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;//³µÏáºÅc£¬×ùÎ»ºÅs 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		string seat1=s1.substr(0,2);
		string seat2=s2.substr(0,2);//ÅÅºÅ 
		if(seat1==seat2) 
		{
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
			{
		
				cout<<1;
				if(abs((int)s1[2]-s2[2])==1)
				{
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
