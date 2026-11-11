#include<bits/stdc++.h>
using namespace std;
int aa,bb,cc,dd,ff;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A') aa++;
	if(b[2]=='B') bb++;
	if(b[2]=='C') cc++;
	if(b[2]=='D') dd++;
	if(b[2]=='F') ff++;
	if(d[2]=='A') aa++;
	if(d[2]=='B') bb++;
	if(d[2]=='C') cc++;
	if(d[2]=='D') dd++;
	if(d[2]=='F') ff++;
	if((dd==1&&ff==1)||(dd==0&&ff==0))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(aa==1&&cc==1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<1;
	}
	return 0;
} 
