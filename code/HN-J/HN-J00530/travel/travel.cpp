#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
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
		if(s1[0]!=s2[0]||s1[1]!=s2[1])
		{
			cout<<"1000";
		}
		else
		{
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))
			{
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1111"; 
				}
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
}

