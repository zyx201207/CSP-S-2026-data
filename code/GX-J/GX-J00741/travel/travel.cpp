
#include<bits/stdc++.h>
using namespace std;
string x,y,l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>l>>r;
	if (x[0]==l[0] && x[1]==l[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (y[0]==r[0] && y[1]==r[1])
	{
		cout<<1;
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if ((y[2]=='A' || y[2]=='B' || y[2]=='C') && (r[2]=='A' || r[2]=='B' || r[2]=='C'))
	{
		cout<<1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if (y[2]==r[2]-1 || y[2]==r[2]+1)
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
