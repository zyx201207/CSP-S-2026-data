#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		int x1=0,x2=0;
	    x1+=s1[1]-'0';
	    x1+=(s1[0]-'0')*10;
	    x2+=s2[1]-'0';
	    x2+=(s2[0]-'0')*10;
	    if(x1!=x2)
	    {
	    	cout<<"000";
		}
		else
		{
			cout<<"1";
			x1=s1[2]-'A'+1;
			x2=s2[2]-'A'+1;
			if((x1>3&&x2>3)||(x1<=3&&x2<=3))
			{
				cout<<"1";
				if(x1>3||x1==2||x2==2)
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
	}
	return 0;
}
