#include<bits/stdc++.h>
using namespace std;
string n,s,k,m,l;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>k>>m;
	if(n!=k)
	{
		cout<<"0000";
	}
	else
	{
		string x,y;
		x=s[0]+s[1];
		y=m[0]+m[1];
		if(x==y)
		{
			char c=s[2];
			char w=m[2];
			if(c>='A'&&c<='C'&&w>='A'&&w<='C')
			{
				if(c=='C'&&w=='D'||c=='D'&&w=='C'||abs(c-w)>1)
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1111";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		} 
	}
	return 0;
}

