#include<bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,b1,b2;
char s[4];
int x;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
    	s[x]+='1';
    	x++;
	}
	else
	{
		s[0]+='0';
		s[1]+='0';
		s[2]+='0';
		s[3]+='0';
		cout<<s;
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])
    {
    	s[x]+='1';
    	x++;
	}
	else
	{
		s[1]+='0';
		s[2]+='0';
		s[3]+='0';
		cout<<s;
		return 0;
	}
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))
    {
    	s[x]+='1';
    	x++;
	}
	else
	{
		if((a2[2]=='D'||a2[2]=='E')&&(b2[2]=='D'||b2[2]=='E'))
		{
			s[x]+='1';
        	x++;
		}
		else
		{
	    	s[2]+='0';
	    	s[3]+='0';
	    	cout<<s;
	    	return 0;
		}
	}
	if(a2[2]+1==b2[2]||a2[2]==b2[2]+1)
    {
    	if((a2[2]!='C'&&b2[2]!='D')&&(a2[2]!='D'&&b2[2]!='C'))
    	{
    		s[x]+='1';
        	x++;
		}
		else
    	{
	    	s[x]+='0';
        	x++;
    	}
	}
	else
	{
		s[x]+='0';
    	x++;
	}
	cout<<s;
	return 0;
 } 
