#include<bits/stdc++.h>
using namespace std;
string ck(string x,string y)
{
	if(x[0]==y[0] && x[1]==y[1])
	{
		if(((x[2]=='D' || x[2]=='F') && (y[2]=='D' || y[2]=='F')) || 
		((x[2]=='A' || x[2]=='B' || x[2]=='C') 
		&& (y[2]=='A' || y[2]=='B' || y[2]=='C')))
		{
			if((x[2]=='A' && y[2]=='B')
			|| (x[2]=='C' && y[2]=='B')
			|| (x[2]=='B' && y[2]=='A')
			|| (x[2]=='B' && y[2]=='C')
			|| (x[2]=='F' && y[2]=='D')
			|| (x[2]=='D' && y[2]=='F'))
			{
				return "111";
			}
			else
			{
				return "110";
			}
		}
		else
		{
			return "100";
		}
	}
	else
	{
		return "000";
	}
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1[0]==y1[0] && x1[1]==y1[1])
	{
		cout<<1; cout<<ck(x2,y2);
	}
	else cout<<"0000";
	
	return 0;
}
