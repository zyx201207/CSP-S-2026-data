#include<bits/stdc++.h>
using namespace std;

long long n;
string s11,s22;
string c1,c2;

int main()
{
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>c1>>s11>>c2>>s22;
	if(c1==c2)
	{
		cout<<'1';
		if(s11[0]==s22[0]&&s11[1]==s22[1])
		{
			cout<<'1';
			if(s11[2]=='D'||s11[2]=='F')
			{
				if(s22[2]=='D'||s22[2]=='F')
				{
					cout<<'1';
					if(s11[2]+1==s22[2]||s11[2]-1==s22[2])
					{
						cout<<'1';
					}
					else cout<<'0';
				}
				else cout<<"00";
			}
			if(s11[2]=='A'||s11[2]=='B'||s11[2]=='C')
			{
				if(s22[2]=='A'||s22[2]=='B'||s22[2]=='C')
				{
					
					cout<<'1';
					if(s11[2]+1==s22[2]||s11[2]-1==s22[2])
					{
						cout<<'1';
					}
					else cout<<'0';
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

