#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,cy,sx,sy;
	cin>>cx;
	cin>>sx;
	cin>>cy;
	cin>>sy;
	int b=0,d=0;
	int e=sx[0],f=sx[1],g=sx[2];
	int h=sy[0],i=sy[1],j=sy[2];
	if(cx[1] == cy[1] && cx[0] == cy[0])
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	if(sx[1] == sy[1] && sx[0] == sy[0] && cx[1] == cy[1] && cx[0] == cy[0] )
	{
	
		cout<<1<<endl;
		b++;
	}
	else
	{
		cout<<0<<endl;
	}
	if( (sx[2] == 'C' &&  sy[2] == 'D') || (sx[2] == 'D' && sy[2] == 'C') ) 
	{
		cout<<0<<endl;
	}
	else if(b==1)
	{
		cout<<1<<endl;
		d++;	
	}
	else
	{
		cout<<0<<endl;
	}
	if(d == 1 && (g - j == 1 || j - g== 1))
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
 } 
