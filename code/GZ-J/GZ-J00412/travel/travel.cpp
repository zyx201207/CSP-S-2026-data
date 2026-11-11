//GZ-J00412 贵阳市观山湖区普瑞学校 袁雅琪
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int b,d,i;
	char c[3]={};
	char e[3]={};
	cin>>b;
	for(i=0;i<3;i++)
	{
		cin>>c[i];
	}
	cin>>d;
	for(i=0;i<3;i++)
	{
		cin>>e[i];
	}
	if(b==d)
	{
		cout<<1;
		if(e[0]==c[0]&&e[1]==c[1])
		{
			cout<<1;
			if(e[2]>'C'&&c[2]>'C')
			{
				cout<<"11";
			}
			else if(e[2]-c[2]==1||e[2]-c[2]==-1)
			{
				cout<<"11";
			}
			else if(e[2]-c[2]==2||e[2]-c[2]==-2)
			{
				cout<<"10";
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
