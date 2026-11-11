#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1;
	int c2;
	char s1[4];
	char s2[4];
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
    cin>>c2;
	for(int i=1;i<=3;i++)	
	{
		cin>>s2[i];
	}
	if(c1==c2)
	{
		cout<<"1";
		if(s1[1]==s2[1] && s1[2]==s2[2])
		{
			cout<<"1";
			if(s1[3]=='A' || s1[3]=='B' || s1[3]=='C')
			{
				if(s2[3]=='A' || s2[3]=='B' || s2[3]=='C')
				{
					cout<<"1";
					if(s1[3]=='A')
					{
						if(s2[3]=='B')
						{
							cout<<"1";
						}
						else
						{
						    cout<<"0";
						}
					}
					else if(s1[3]=='B')
					{
						cout<<"1";
					}
					else if(s1[3]=='C')
					{
						if(s2[3]=='B')
						{
							cout<<"1";
						}
						else
						{
						    cout<<"0";
						}
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else if(s1[3]=='D' || s1[3]=='F')
			{
				if(s2[3]=='D' || s2[3]=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
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
