#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string r=s1.substr(2,1),x=s2.substr(2,1); 
	if(c1==c2)
	{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<"1";
			if(s1.substr(2,1)<="C"&&s2.substr(2,1)<="C")
			{
				cout<<"1";
				if(((r=="A"||x=="A")&&(r=="B"||x=="B"))||((r=="C"||x=="C")&&(r=="B"||x=="B")))
				{
					cout<<"1";
				}
				else
					cout<<"0";
			}
			else if(s1.substr(2,1)>="D"&&s2.substr(2,1)>="D")
			{
				cout<<"11";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";


	return 0;
}
