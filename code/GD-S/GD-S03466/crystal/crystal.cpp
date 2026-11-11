#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N=5e5+10;

ll n,m;
ll a[N];
ll b[N];
ll c[N];
ll ans=0;

ll r();

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=r();
	m=r();
	for(int i=1;i<=n;i++)
		a[i]=r();
	sort( a+1 , a+n+1 , [](ll x,ll y){ return x<y; } );
	for(ll i=1,j=1,x=0;i<=n;i++)
	{
		b[i] = a[i+1] - a[i];
		c[i] = c[i-1] + b[i];
		x += j * b[i];
		if( x>m )
		{
			if( b[i]==0 )
			{
				j++;
				ans = max( ans , j );
			}
			else
			{
				ans = max( ans , j );
				while( x>m )
				{
					x -= c[i] - c[i-j];
					j--;
				}
			}
		}
		else if( x==m )
		{
			if( b[i]==0 ) j++;
			ans = max( ans , j+1 );
		}
		else j++;
	}
	cout << ans << endl;
	
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
