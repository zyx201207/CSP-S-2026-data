#include<bits/stdc++.h>

#define ll long long

#define plc pair<ll,char>
#define f first
#define s second

using namespace std;

ll n;
vector<plc> a;
ll ans=0;

ll r();

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	n=r();
	ll x=r(),siz=0;
	char c=getchar();
	a.push_back( { x , c } );
	siz++;
	for(int i=2;i<=n;i++)
	{
		x=r();
		c=getchar();
		if( c == a[siz-1].s )
			a[siz-1].f += x;
		else
		{
			a.push_back( { x , c } );
			siz++;
		}
	}
	
	for(int i=0,j=siz-1;i<j;)
	{
		x = min( a[i].f , a[j].f );
		if( a[i].s != a[j].s )
			ans += x;
		a[i].f -= x;
		a[j].f -= x;
		if( a[i].f == 0 ) i++;
		if( a[j].f == 0 ) j--;
	}
	
	cout<<ans<<endl;
	
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
