#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1[4],a2[4];
	char b1[4],b2[4];
	int n,m,x,y;
	char c,d;
	cin>>a1+1>>a2+1;
	cin>>b1+1>>b2+1;
	n=(a1[1]-'0')*10+a1[2]-'0';
	m=(a2[1]-'0')*10+a2[2]-'0';
	x=(b1[1]-'0')*10+b1[2]-'0';
	y=(b2[1]-'0')*10+b2[2]-'0';
	c=a2[3];
	d=b2[3];
	if (n==x)
	{
		cout<<1;
		if(m==y)
		{
			cout<<1;
			if (((c=='A' || c=='B' || c=='C') && (d=='A' || d=='B' || d=='C')) || ((c=='D' || c=='F') && (d=='D' || d=='F')))
			{
				cout<<1;
				if((c=='A' && d=='B') || (c=='B' && d=='C'))
					cout<<1;
				else if(c=='D' && d=='F')
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}