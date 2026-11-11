#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d,s="";
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		s+="1";
	}
	else
	{
		s+="0000";
		cout<<s<<'\n';
		return 0;
	}
	string q="",w="";
	for(int i=0;i<b.size()-1;i++)
	{
		q+=b[i];
	}
	for(int i=0;i<b.size()-1;i++)
	{
		w+=d[i];
	}
	if(q==w)
	{
		s+="1";
	}
	else
	{
		s+="000";
		cout<<s<<'\n';
		return 0;
	}
	int x=b[2]-'0',y=d[2]-'0';
	if(x<=19&&y<=19)
	{
		s+="1";
		if(abs(x-y)==1)
		{
			s+="1";
		}
		else
		{
			s+="0";
		}
	}
	else if(x>=20&&y>=20)
	{
		s+="11";
	}
	else
	{
		s+="00";
	}
	cout<<s<<'\n';
	return 0;
}
