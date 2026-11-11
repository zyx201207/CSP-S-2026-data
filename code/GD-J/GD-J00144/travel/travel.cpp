#include<bits/stdc++.h>
using namespace std;
int cr,numr,cx,numx;
char sr,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>numr>>sr>>cx>>numx>>sx;
	if(cr!=cx)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(numr!=numx)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(sr=='F') sr='G';
	if(sx=='F') sx='G';
	if(sr=='D') sr='F';
	if(sx=='D') sx='F';
	if(abs(sr-sx)>2)
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(sr=='D') sr++;
	if(sx=='D') sx++;
	if(abs(sr-sx)>1) cout<<0;
	else cout<<1;
	return 0;
}
