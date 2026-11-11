#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<1;
		int temp=(s1[0]-'0')*10+s1[1]-'0';
		int temp1=(s2[0]-'0')*10+s2[1]-'0';
		if(temp==temp1)
		{
			cout<<1;
			char t=s1[2],t1=s2[2];
			int flag,flag1;
			if(t=='D'||t=='E') flag=1;
			else flag=0;
			if(t1=='D'||t1=='E') flag1=1;
			else flag1=0;
			if(flag==flag1)
			{
				cout<<1;
				if(s2[2]-s1[2]==1&&s2[2]!='D'||s1[2]-s2[2]==1&&s1[2]!='D')
					cout<<1;
				else cout<<0;
			} 
			else cout<<"00";
		}
		else 
		{
			cout<<"000";
		}
	}
	else cout<<"0000";
	
	return 0;
} 
