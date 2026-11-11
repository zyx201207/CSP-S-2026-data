#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int pan(char n)
{
	if(n=='a' || n=='b' || n=='c') return 6;
	else return 7;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) 
	{
		if(b[0]==d[0] && b[1]==d[1]) 
		{
			int x,y;
			if(b[2]=='A' || b[2]=='B' || b[2]=='C') x=1;
			else x=0;
			if(d[2]=='A' || d[2]=='B' || d[2]=='C') y=1;
			else y=0;
			if(x==y) 
			{
				if(b[2]==d[2] || b[2]-1==d[2] || b[2]+1==d[2])
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else 
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
