#include<bits/stdc++.h>
using namespace std;
int fun(char c)
{
	if(c=='A'||c=='B'||c=='C')
		return 1;
	else
		return 2;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
		cout<<"1";
	if(!(b[0]==d[0]&&b[1]==d[1]))
	{
		cout<<"000";
		return 0;
	}
	else
		cout<<"1";
	if(!(fun(b[2])==fun(d[2])))
	{
		cout<<"00";
		return 0;
	}
	else
		cout<<"1";
	if((fun(b[2])==1&&abs(b[2]-d[2])==1)||fun(b[2])==2)
		cout<<"1";
	else
		cout<<"0";
	return 0;
} 
