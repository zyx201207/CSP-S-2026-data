#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
bool qu1,qu2,qu3,qu4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	for(int i=0;i<cx.size();i++)
	    if(cx[i]!=cy[i])
	        qu1=true;
	if(qu1)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int sxze=sx.size();
	sxze--;
	for(int i=0;i<sxze;i++)
	    if(sx[i]!=sy[i])
	        qu2=true;
	if(qu2)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(sx[2]=='C'&&sy[2]=='D')
	{
		cout<<"00";
		return 0;
	}
	if(sx[2]=='D'&&sy[2]=='C')
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	int nrx=(int)sx[2],nry=(int)sy[2];
	if(abs(nrx-nry)==1)
		cout<<"1";
	else
	    cout<<"0";
	return 0;
}
