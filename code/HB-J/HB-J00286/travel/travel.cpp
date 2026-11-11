#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","stdin","r");
	freopen("travel.out","stdout","w");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<"1";
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if((c2[1]==s2[1])&&(c2[0]==s2[0])&&(c1==s1)) cout<<"1";
	else
	{
		cout<<"000"<<endl;
		return 0;
	}
	if((c2[1]==s2[1])&&(c2[0]==s2[0]))
	{
		if(c2[2]=='A')
		{
			if(s2[2]=='B'||s2[2]=='C')
			{
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(c2[2]=='B')
		{
			if(s2[2]=='A'||s2[2]=='C')
			{
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(c2[2]=='C')
		{
			if(s2[2]=='B'||s2[2]=='A')
			{
				cout<<"1";
			}
			else cout<<"0";
		}
		else if(c2[2]=='D')
		{
			if(s2[2]=='F')
			{
				cout<<"1";
			}
			else cout<<"0";
		}
		else
		{
			if(s2[2]=='D')
			{
				cout<<"1";
			}
			else cout<<"0";
	    }
	}
	else
	{
		cout<<"00"<<endl;
		return 0;
	}
	if((c2[1]==s2[1])&&(c2[0]==s2[0]))
	{
		if((c2[2]=='A'&&s2[2]=='B')||(c2[2]=='B'&&s2[2]=='A')||(c2[2]=='B'&&s2[2]=='C')||(c2[2]=='C'&&s2[2]=='B')||(c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D'))
		{
			cout<<"1";
		}
		else cout<<"0"<<endl;
		return 0;
	}
	else cout<<"0"<<endl;
	return 0;
}
