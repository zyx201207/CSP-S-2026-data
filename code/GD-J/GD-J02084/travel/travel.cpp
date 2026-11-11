#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,g,w;cin>>s>>t>>g>>w;
	if(s==g)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		cout<<"000";
		return 0;
	}
	if((t[0]==w[0])&&(t[1]==w[1]))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		cout<<"00";
		return 0;
	}
	if((t[2]<='C'&&w[2]<='C')||(t[2]>='D'&&w[2]>='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if((t[2]+1==w[2]||t[2]-1==w[2])||(t[2]=='D'&&w[2]=='F')||(t[2]=='F'&&w[2]=='D'))
	{
		if((t[2]=='C'&&w[2]=='D')||(t[2]=='D'&&w[2]=='C'))
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
