#include<bits/stdc++.h>

using namespace std;

struct ticke
{
	string c;
	string s;
}R,X;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>R.c>>R.s>>X.c>>X.s;
	
	if( R.c!=X.c )
	{
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	
	string a,b;
	a+=R.s[0];
	a+=R.s[1];
	b+=X.s[0];
	b+=X.s[1];
	
	if( a!=b )
	{
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	
	char x=R.s[2],y=X.s[2];
	
	if((x<='C' && y>'C') || (x>'C' && y<='C'))
	{
		cout<<"00"<<endl;
		return 0;
	}
	cout<<"1";
	
	if(x==y+1 || y==x+1)
		cout<<"1"<<endl;
	else if((x=='D' && y=='F') ||(x=='F' && y=='D'))
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	
	return 0;
}
