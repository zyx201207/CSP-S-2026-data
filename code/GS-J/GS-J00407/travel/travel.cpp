#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string nr,mr,nx,mx;
	cin>>nr>>mr>>nx>>mx;
    cout<<"111";
	if(mr[3]=='A' && mx[3]=='B')
	{
	    cout<<"1";
	}
	else if(mr[3]=='B' && mx[3]=='A')
	{
	    cout<<"1";
	}
	else if(mr[3]=='B' && mx[3]=='C')
	{
	    cout<<"1";
	}
    else if(mr[3]=='C' && mx[3]=='B')
	{
	    cout<<"1";
	}
	else if(mr[3]=='D' && mx[3]=='E')
	{
	    cout<<"1";
	}
	else if(mr[3]=='E' && mx[3]=='D')
	{
	    cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0; 
 } 
