#include <bits/stdc++.h>
using namespace std;
string b,d;
long long a,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		long long x=(b[0]-'0')*10+(b[1]-'0');
		long long y=(d[0]-'0')*10+(d[1]-'0');
		if(x==y)
		{
			cout<<1;
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
			{
				cout<<1;	
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B'))	cout<<1;
				else	cout<<0;	
			}
			else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))	cout<<1<<1;
			else	cout<<0<<0;
		}
		else	cout<<0<<0<<0;
	}	
	else	cout<<0<<0<<0<<0;
	
	return 0;
} 
