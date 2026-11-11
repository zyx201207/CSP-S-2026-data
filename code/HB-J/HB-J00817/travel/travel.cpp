#include <bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2)
	{
		cout<<1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1])
		{
			cout<<1;
			bool flag1,flag2;
			if(s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C') flag1=0;
			else flag1=1;
			if(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C') flag2=0;
			else flag2=1;
			if(flag1==flag2)
			{
				cout<<1;
				if(flag1==0)
				{
					if((s_1[2]!='B'&&s_2[2]!='B')||(s_1[2]==s_2[2])) cout<<0;
					else cout<<1;
				}
				if(flag1==1)
				{
					if(s_1[2]==s_2[2]) cout<<0;
					else cout<<1;
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
