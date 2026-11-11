#include <bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x) 
	{
		cout<<'1';
		if(b[0]==y[0]&&b[1]==y[1])
		{
			cout<<'1';
			if((b[2]>='A'&&b[2]<='C'&&y[2]>='A'&&y[2]<='C')||(b[2]=='D'&&y[2]=='F')||(b[2]=='F'&&y[2]=='D'))
			{
				cout<<'1';
				if(b[2]+1==y[2]||y[2]+1==b[2])
				{
					cout<<'1';
				}
				else 
				{
					cout<<'0';
				}
			}
			else cout<<"00";
		}	
		else cout<<"000";
	}
	else cout<<"0000";
	cout<<endl;
	return 0;
} 
