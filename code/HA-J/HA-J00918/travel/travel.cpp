#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if (a==d)
	{
		cout<<"1";
		if (s[0]==f[0]&&s[1]==f[1])
		{
			cout<<"1";
			if (s[2]-'A'<=2&&f[2]-'A'<=2)
			{
				cout<<"1";
				if (s[2]-'A'==f[2]-'A'+1||s[2]-'A'+1==f[2]-'A')
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
				if (s[2]-'A'>=3&&f[2]-'A'>=3)
				{
					cout<<"1";
					if (s[2]-'A'==f[2]-'A'+1||s[2]-'A'+1==f[2]-'A')
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
				
		    }
		    if ((s[2]=='C'&&f[2]=='D')||(s[2]=='D'&&f[2]=='C'))
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
