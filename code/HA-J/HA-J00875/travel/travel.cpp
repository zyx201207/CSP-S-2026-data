#include <bits/stdc++.h>
using namespace std;
string a,b;
typedef long long ll;
ll q,p,x,y;
bool l,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>a>>p>>b;
	if(q==p)
	{
		m=1;
		cout<<"1";
	}
	else
	{
		m=0;
		cout<<"0";
	}
	if(!m)
	{
		cout<<"000";
		return 0;
	}
	if(a[0]==b[0] && a[1]==b[1])
	{
		l=1;
		cout<<"1";
	}
	else
	{
		l=0;
		cout<<"0";
		}
	x=a[2]-'A'+'0';
	y=b[2]-'A'+'0';
	if(l)
	{
		if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A'))
			cout<<"1";
		else if((a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B'))
			cout<<"1";
		else if((a[2]=='A'&&b[2]=='C')||(a[2]=='C'&&b[2]=='A'))
			cout<<"1";
		else if((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	if(a[2]=='D'&&b[2]=='F')
		cout<<"1";
	else if(a[2]=='A'&&b[2]=='B')
		cout<<"1";
	else if(a[2]=='B'&&b[2]=='C')
		cout<<"1";
	else
		cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
