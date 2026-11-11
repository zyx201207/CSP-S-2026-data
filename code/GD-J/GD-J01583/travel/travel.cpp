#include<bits/stdc++.h>
using namespace std;
char x[20];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin>>x[i];
	}
	long long cx11=(x[1]-'0')*10+x[2]-'0',cx22=(x[6]-'0')*10+x[7]-'0';
	long long p11=(x[3]-'0')*10+x[4]-'0',p22=(x[8]-'0')*10+x[9]-'0';
	long long zm11=x[5]-'A'+1,zm22=x[10]-'A'+1;
	//cout<<cx11<<","<<p11<<","<<zm11<<" ; "<<cx22<<","<<p22<<","<<zm22;
	if(cx11==cx22)
	{
		cout<<"1";
		if(p11==p22)
		{
			cout<<"1";
			if(zm11<=3 && zm22<=3)
			{
				cout<<"1";
				if( abs(zm11-zm22)==1 )
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(zm11>=4 && zm22>=4)
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
