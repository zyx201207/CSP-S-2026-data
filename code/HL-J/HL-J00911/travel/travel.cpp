#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx)
	{
		cout<<"0000";
		return 0;
	}	
	if(cr==cx) cout<<1;
	else cout<<0;
	if(sx[1]-'0'==sr[1]-'0') cout<<1;
	else cout<<0;
	if(sx[1]-'0'==sr[1]-'0')cout<<1;
	else cout<<0;
	int x=sx[2]-'0';
	int r=sr[2]-'0';
	if(abs(x-r)==1)
	{
		if((x==67&&r==68)||(r==67&&x==68)) cout<<0;
		else cout<<1;
	}
	else if((x==68&&r==70)||(x==70&&r==68)) cout<<1;
	else cout<<0;
	return 0;
}