#include<bits/stdc++.h>
using namespace std;
string ca,cb,a,b;
int pa,pb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>a>>cb>>b;
	pa=a[2]-'A'+1;
	pb=b[2]-'A'+1;
	if(pa==4)
	{
		pa++;
	}
	if(pb==4)
	{
		pb++;
	}
	if(ca!=cb)
	{
		cout<<"0000";
	}
	else
	{
	cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1])
		{
			cout<<"1";
			if((pa<=3&&pb<=3)||(pa>=4&&pb>=4))
			{
				cout<<"1";
				if(abs(pa-pb)==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
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
	return 0;
}
