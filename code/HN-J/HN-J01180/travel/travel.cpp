#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string x,y;
	cin>>n>>x>>m>>y;
	if(m!=n)
	{
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(x[0]==y[0] && x[1]==y[1])
	{
		cout<<'1';
		if(x[2]<='C' && y[2]<='C')
		{
			cout<<'1';
			if(x[2]-'A'-1==y[2]-'A' || y[2]-'A'-1==x[2]-'A')
			{
				cout<<'1';
				return 0;
			}else cout<<'0';
		}
		else if(x[2]>='D' && x[2]<='F' && y[2]<='F' && y[2]>='D')
		{
			cout<<'1';
			if(x[2]-'A'-1==y[2]-'A' || y[2]-'A'-1==x[2]-'A')
			{
				cout<<'1';
				return 0;
			}else cout<<'0';
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
