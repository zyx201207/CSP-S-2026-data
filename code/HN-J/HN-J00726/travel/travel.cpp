#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1,S1,C2,S2;
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2)
	{
		cout<<"1";
		if((S1[0]==S2[0])&&(S1[1]==S2[1]))
		{
			cout<<"1";
			if(S1[2]+'1'==S2[2]||S2[2]-'1'==S1[2]||S2[2]+'1'==S1[2]||S1[2]-'1'==S2[2])
			{
				cout<<"1";
				if(S2[2]>='A'&&S2[2]<='C'&&(S2[2]=='D'||S2[2]=='F'))
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
	else 
	{
		cout<<"0000";
	}
	return 0;
}
