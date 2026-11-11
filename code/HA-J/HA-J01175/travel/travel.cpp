#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	bool q=1,w=1,e=1,r=0,t=0;
	cin>>n>>m>>a>>b;
	if(n[0]==a[0]&&n[1]==a[1])
		cout<<"1";
	else
	{
		q=0;
		cout<<"0";
	}
	if(q&&m[0]==b[0]&&m[1]==b[1])
		cout<<"1";
	else
	{
		w=0;
		cout<<"0";
	}
	if((m[2]=='D'&&b[2]=='F')||(m[2]=='F'&&b[2]=='D'))
	    r=1;
	else if((m[2]=='A'&&(b[2]=='B'||b[2]=='C'))||(m[2]=='B'&&(b[2]=='A'||b[2]=='C'))||(m[2]=='C'&&(b[2]=='B'||b[2]=='A')))
		t=1;
	if(w&&(r||t))
		cout<<"1";
	else
	{
		e=0;
		cout<<"0";
	}
	if(!e||(m[2]=='A'&&b[2]=='C')||(m[2]=='C'&&b[2]=='A'))
		cout<<"0";
	else
		cout<<"1";
	return 0;
}
