//GZ-J00535,北京市第八中学贵阳分校，周仕洁 
#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1>>c2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	string s1[3],s2[3];
	for(int i=0;i<=3;i++)
	{
		cin>>s1[i];
		for(int j=0;j<=3;j++)
		{
			cin>>s2[j];
			if(s1[1]==s2[1]&&s1[2]==s2[2])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	return 0;
}
