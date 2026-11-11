#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,a,b;
	cin>>x>>y>>a>>b;
	if(x==a)
		cout<<1;
	else
		cout<<0;
	int s=y[0]*10+y[1],c=b[0]*10+b[1];
	if(s==c&&x==a)
		cout<<1;
	else
		cout<<0;
	char i=y[2],j=b[2];
	if(s==c&&x==a)
	{
		if(i=='A'&&(j=='B'||j=='C')||i=='B'&&(j=='A'||j=='C')||i=='C'&&(j=='B'||j=='A'))
			cout<<1;
		else if(i=='F'&&j=='D'||i=='D'&&j=='F')
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
	if(x==a&&s==c&&(i=='A'&&j=='B'||i=='B'&&(j=='A'||j=='C')||i=='C'&&j=='B'||i=='D'&&j=='F'||i=='F'&&j=='D'))
		cout<<1;
	else
		cout<<0;
	return 0;
}
