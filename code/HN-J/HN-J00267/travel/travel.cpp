#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,aa,bb;
bool check()
{
	
	if(aa[2]=='A'&&(bb[2]=='B'||bb[2]=='C'))
	{
		return true;
	}
	if(aa[2]=='B'&&(bb[2]=='A'||bb[2]=='C'))
	{
		return true;
	}
	if(aa[2]=='C'&&(bb[2]=='A'||bb[2]=='B'))
	{
		return true;
	}
	if(aa[2]=='F'&&bb[2]=='D')
	{
		return true;
	}
	if(aa[2]=='D'&&bb[2]=='F')
	{
		return true;
	}
	return false;
}
bool check2()
{
	if(aa[2]=='A'&&bb[2]=='B')
	{
		return true;
	}
	if(aa[2]=='B'&&(bb[2]=='A'||bb[2]=='C'))
	{
		return true;
	}
	if(aa[2]=='C'&&bb[2]=='B')
	{
		return true;
	}
	if(aa[2]=='F'&&bb[2]=='D')
	{
		return true;
	}
	if(aa[2]=='D'&&bb[2]=='F')
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b)
	{
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			if(check())
			{
				if(check2())
				{
					cout<<"1"<<"1"<<"1"<<"1"<<'\n';
				}
				else
				{
					cout<<"1"<<"1"<<"1"<<"0"<<'\n';
				}
			}
			else
			{
				cout<<"1"<<"1"<<"0"<<"0"<<'\n';
			}
		}
		else
		{
			cout<<"1"<<"0"<<"0"<<"0"<<'\n';
		}
	}
	else
	{
		cout<<"0"<<"0"<<"0"<<"0"<<'\n'; 
	}
	return 0;
}
