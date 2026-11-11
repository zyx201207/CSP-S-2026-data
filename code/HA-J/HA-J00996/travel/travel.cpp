#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			int k1=0,k2=0;
			k1=s1[2]-'A';
			k2=s2[2]-'A';
			if((k1<=2&&k2<=2)||(k1>=3&&k2>=3))
			{
				cout<<1;
				if(k1==k2-1||k1==k2+1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
				return 0;
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}

	return 0;
}

