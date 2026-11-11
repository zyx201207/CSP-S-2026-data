#include<bits/stdc++.h>
using namespace std;
int a;
string a1,b1,a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<"1";
			if((a2[2]>=68&&b2[2]>=68)||(a2[2]<68&&b2[2]<68))
			{
				cout<<"1";
				if((a2[2]>=68&&b2[2]>=68)||(a2[2]<=66&&b2[2]<=66)||((a2[2]<68&&b2[2]<68)&&(a2[2]>=66&&b2[2]>=66)))
				cout<<"1";
				else
				cout<<"0";
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
