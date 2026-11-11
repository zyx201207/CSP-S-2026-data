#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int check(string a)
{
	if(a[2]=='C' || a[2]=='B' || a[2]=='A') return 1;
	else return 0;
}
int hs(string a,string b)
{
	if((a[2]=='C' && b[2]=='B') || (a[2]=='B' && b[2]=='A') || (a[2]=='B' && b[2]=='C') || (a[2]=='A' && b[2]=='B'))
	{
		return 1;
	}
	else return 0;
}
int hss(string a,string b)
{
	if((a[2]=='F' && b[2]=='D') || (a[2]=='D' && b[2]=='F'))
	{
		return 1;
	}
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) 
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<"1";
			if(check(s1)==check(s2))
			{
				cout<<"1";
				if(check(s1)==1)
				{
					if(hs(s1,s2)==1) cout<<"1";
					else cout<<"0";
				} 
				else
				{
					if(hss(s1,s2)==1) cout<<"1";
					else cout<<"0";
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
	return 0;
}
