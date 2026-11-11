#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(char(b[0])==char(d[0])&&char(b[1])==char(d[1]))
		{
			cout<<1;
			if((char(b[2])=='D'&&char(d[2])=='F')||(char(b[2])=='F'&&char(d[2])=='D')||(char(b[2])!='D'&&char(d[2])!='F'&&char(b[2])!='F'&&char(d[2])!='D'))
			{
				cout<<1;
				if((char(b[2])=='D'&&char(d[2])=='F')||(char(b[2])=='D'&&char(d[2])=='F')||(char(b[2])!='D'&&char(d[2])!='F'&&(char(b[2])=='B'||char(d[2])=='B'))||(char(b[2])!='F'&&char(d[2])!='D'&&(char(b[2])=='B'||char(d[2])=='B')))
				{
					cout<<1;
				 } 
				 else
				 {
				 	cout<<0;
				 }
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
 } 
