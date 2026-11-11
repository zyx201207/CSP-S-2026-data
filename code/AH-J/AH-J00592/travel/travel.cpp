#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<1;
			s1.erase(0,2),s2.erase(0,2);
			if(((s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C"))||((s1=="D"||s1=="F")&&(s2=="D"||s2=="F")))
			{
				cout<<1;
				if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="C")||(s1=="D"&&s2=="F"))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
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
