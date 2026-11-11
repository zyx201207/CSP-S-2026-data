#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,c;
	string b,d,q,w,e,r,t;
	cin>>a>>b>>c>>d;

	if(a!=c)
	{
		cout<<"0000";
    } 
	else if(a==c&&b[0]!=d[0]||b[1]!=d[1])
	{
		
		cout<<1000;
	}
	
		else if(a==c&&b[0]==d[0]&&b[1]==d[1])
	{
	
		cout<<1110;
	
	}

	

	return 0;
}
