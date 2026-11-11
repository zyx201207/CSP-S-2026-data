#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
		int x=(s1[2]-'A')+1;
		int y=(s2[2]-'A')+1;
		if(x<=3&&y<=3)
		{
			cout<<"1";
			if((x==1&&y==3)||(x==3&&y==1))
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<"1"<<endl;
			}
		}
		else if(x>3&&y>3)
		{
			cout<<"11"<<endl;
		}
		else
		{
			cout<<"00"<<endl;
		}
	}
	else
	{
		cout<<"000"<<endl;
	}
	return 0;
}
