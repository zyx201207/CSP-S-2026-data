#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char c_r,c_x;
	char s_r[3],s_x[3];
	cin>>c_r>>s_r>>c_x>>s_x;
	char a=s_r[0],b=s_r[1],c=s_r[2];
	char d=s_x[0],e=s_x[1],f=s_x[2];
	if(c_r==c_x)
	{
		cout<<"1";
		if(b=e)
		{
			cout<<"1";
			if(c=='A'||c=='B'||c=='C')
			{
				if(f=='A'||f=='B'||f=='C')
				{
					cout<<"1";
					if(c=='A' && f=='B')
					{
						cout<<"1";
					}
					else if(c=='B' && f=='A')
					{
						cout<<"1";
					}
					else if(c=='B' && f=='C')
					{
						cout<<"1";
					}
					else if(c=='C' && f=='B')
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
			if(c=='D'||c=='F')
			{
				if(f=='D'||f=='F')
				{
					cout<<"1";
					if(c=='D' && f=='F')
					{
						cout<<"1";
					}
					else if(c=='F' && f=='D')
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
