#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt,sum;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<"1";
    else 
    {
 
		cout<<"0000";
		return 0;
	}
    if(b[0]==d[0])
    {
		if(b[1]==d[1])
		{
			
		cout<<"1";
		sum=1;
	    }
		else
		{
			cout<<"0";
		}
	}
    else cout<<"0";
    if(sum==1)
    {
	if(b[2]=='A' && d[2]=='B')
	{
		cout<<"1"; 
		cnt=1;
	}
   if(b[2]=='B' && d[2]=='C')
	{
      cout<<"1"; 
		cnt=1;
	}
	if(b[2]=='A' && d[2]=='c')
	{
		cout<<"1"; 
		cnt=1;
	}
    if(b[2]=='D' && d[2]=='F')
    {
		cout<<"1"; 
		cnt=1;
	}
   if(b[2]=='F' && d[2]=='D')
    {
		cout<<"1";
		cnt=1;
	}
	if(b[2]=='C' && d[2]=='B')
	{
		cout<<"1"; 
		cnt=1;
	}
	if(b[2]=='B' && d[2]=='A')
	{
		cout<<"1"; 
		cnt=1;
	}
	if(b[2]=='C' && d[2]=='A')
	{
		cout<<"1";
		cnt=1;
	}
	if(cnt==0)cout<<"0";	
    }
    else cout<<"0";
    if(cnt==1)
    {
		   if(b[2]=='A' && d[2]=='B')
	{
		cout<<"1"; 
		return 0;
	}
   if(b[2]=='B' && d[2]=='C')
	{
      cout<<"1"; 
		return 0;
	}
    if(b[2]=='D' && d[2]=='F')
    {
		cout<<"1"; 
		return 0;
	}
   if(b[2]=='F' && d[2]=='D')
    {
		cout<<"1";
		return 0;
	}
	if(b[2]=='C' && d[2]=='B')
	{
		cout<<"1"; 
		return 0;
	}
	if(b[2]=='B' && d[2]=='A')
	{
		cout<<"1"; 
		return 0;
	}
	cout<<"0";
	}
	else cout<<"0";
 

    return 0;
}
