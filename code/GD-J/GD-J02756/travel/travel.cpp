#include <bits/stdc++.h> 
using namespace std;
long long a,b,ap,bp,ah,bh;
string s1,s2;
char al,bl;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')ap=ap*10+(s1[i]-'0');
		else al=s1[i];
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')bp=bp*10+(s2[i]-'0');
		else bl=s2[i];
	}
	ah=s1[s1.size()-1]-'A';
	bh=s2[s2.size()-1]-'A';
	if(a==b)
	{
		cout<<1;
		if(ap==bp)
		{
			cout<<1;
			if((('A'<=al&&'C'>=al)&&('A'<=bl&&'C'>=bl))||('D'<=al&&'F'>=al)&&('D'<=bl&&'F'>=bl))
			{
				cout<<1;
				if(max(ah,bh)-min(ah,bh)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else 
	{
		cout<<"0000";
	}
	return 0;
}
