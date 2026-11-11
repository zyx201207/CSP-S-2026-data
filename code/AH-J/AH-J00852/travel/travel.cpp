#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,d1,d2;
    cin>>s1>>s2>>d1>>d2;
    if(s1!=d1)
    {
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(s2[0]!=d2[0]||s2[1]!=d2[1])
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if((s2[2]=='F'&&d2[2]=='D')||(s2[2]=='C'&&d2[2]=='B')||(s2[2]=='B'&&d2[2]=='A')||(d2[2]=='F'&&s2[2]=='D')||(d2[2]=='C'&&s2[2]=='B')||(d2[2]=='B'&&s2[2]=='A'))
			{
				cout<<"11";
				return 0;
			}
			else
			{
				if(s2[2]=='C'&&d2[2]=='A')
				{
					cout<<"10";
					return 0;
				}
				else cout<<"00";
			}
	    }
	}
    return 0;
}
