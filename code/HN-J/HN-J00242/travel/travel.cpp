#include<bits/stdc++.h> 
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			int ss1=s1[2]-'A'+1,ss2=s2[2]-'A'+1;
			if(ss1<=3&&ss2<=3||ss1>3&&ss2>3)
			{
				cout<<"1";
				if(ss1+1==ss2||ss1-1==ss2)
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
			return 0;
		}
	}
	return 0; 
}
//Trick||Treat!
