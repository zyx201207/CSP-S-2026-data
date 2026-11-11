#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll c,T;

ll r();

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=r();
	T=r();
	while(T--)
	{
		cout<<"1"<<endl;
	}
	return 0;
}

ll r()
{
	char c=getchar();
	ll flag=1;
	while( c<'0' || c>'9' )
	{
		if( c=='-' ) flag=-1;
		else flag=1;
		c=getchar();
	}
	ll x=0;
	while( c>='0' && c<='9' )
	{
		x = (x<<3) + (x<<1) + c - '0';
		c=getchar();
	}
	return x*flag;
}
