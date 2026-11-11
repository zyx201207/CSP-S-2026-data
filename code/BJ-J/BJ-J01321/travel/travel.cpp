#include<bits/stdc++.h>
using namespace std;
char a[3],b[3],c[3],d[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
	if(a[0]==c[0]&&a[1]==c[1])
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F')
		cout<<1<<1;
	else if(b[2]=='F'&&d[2]=='D')
		cout<<1<<1;
	else if(b[2]=='A'&&d[2]=='B')
		cout<<1<<1;
	else if(b[2]=='B'&&d[2]=='C')
		cout<<1<<1;
	else if(b[2]=='A'&&d[2]=='C')
		cout<<1<<0;
	else
		cout<<0<<0;
	fclose(stdin);
	fclose(stdout);
return 0;
}
