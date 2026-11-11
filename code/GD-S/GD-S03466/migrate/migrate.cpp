#include<bits/stdc++.h>

#define ll long long

#define pll pair<ll,ll>
#define f first
#define s second

using namespace std;

const int N=2e6+10;
ll c,T,a[N];
ll lin[5010][5010];
ll ans=0;
ll n;
ll d;

ll r();

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=r();
	T=r();
	while(T--)
	{
		n=r();
		d=r();
		if(n==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(n==1)
		{
			a[1]=r();
			cout<<"0"<<endl;
			continue;
		}
		if(n==2)
		{
			a[1]=r();
			a[2]=r();
			cout<<"0"<<endl;
			continue;
		}
		
		a[1]=r();
		a[2]=r();
		ll derta=abs(a[1]-a[2]);
		bool flag=1;
		for(int i=3;i<=n;i++)
		{
			a[i]=r();
			if( abs(a[i] - a[i-1]) != derta ) flag=0;
		}
		if( flag )
		{
			if( derta*2<=d)
			{
				if( n-2*(d/derta)+1>0 )
					cout<<n-2*(d/derta)+1<<endl;
				else
					cout<<"0"<<endl;
				continue;
			}
			else
			{
				cout<<"0"<<endl;
				continue;
			}
		}
		else if( abs(a[n] - a[1]) <= d*2 )
		{
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			ans=0;
			memset( lin , 0 , sizeof(lin) );
			for(int i=1;i<=n;i++)
			{
				for(int k=i+1;k<=n;k++)
				{
					for(int j=k+1,x,y,z;j<=n;j++)
					{
						x=abs(a[i]-a[k]);
						y=abs(a[j]-a[k]);
						z=abs(a[i]-a[j]);
						if( x<=d && y<=d && z>d )
						{
							lin[i][j]++;
							if( lin[i][j] == 2 )
								ans++;
							else if( lin[i][j] == 3 )
								ans--;
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
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
