#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc cout
#define ull unsigned long long
ll sz[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,t;
	ll n,d;
	ll ans=0;
	ll pd=0;
	cin>>c>>t;
	while(t--)
	{
		pd=0;
		ans=0;
		cin>>n>>d;
		for(ll i=0;i<n;i++)
		{
			cin>>sz[i];
			if(i==0&&sz[i]<0)
			{
				pd=abs(sz[i]);
			}
			sz[i]+=pd;
		}
		for(ll i=0;i<n;i++)
		{
			ll xb=upper_bound(sz,sz+n,sz[i]+d)-sz;
			xb-=1;
			if(xb!=n-1)
			{
				if(xb-i==2)
				{
					if(sz[xb+1]-sz[xb-1]<=d) 
					{
						ans++;
						if(i!=0&&sz[i]-sz[i-1]<=d&&sz[i+1]-sz[i-1]>d) ans++;
						if(sz[xb+2]-sz[xb+1]<=d&&sz[xb+2]-sz[xb]>d) ans++;
						if(i!=0&&sz[i]-sz[i-1]<=d&&sz[i+1]-sz[i-1]>d&&sz[xb+2]-sz[xb+1]<=d&&sz[xb+2]-sz[xb]>d) ans++;
					}
				}
				else if(xb-n>2)
				{
					if(sz[xb+1]-sz[xb-1]<=d&&sz[xb+1]-sz[xb-2]>d) ans++;
					if(i!=0&&sz[i]-sz[i-1]<=d&&sz[i+1]-sz[i-1]>d) ans++;
					if(sz[xb+2]-sz[xb+1]<=d&&sz[xb+2]-sz[xb]>d) ans++;
					if(i!=0&&sz[i]-sz[i-1]<=d&&sz[i+1]-sz[i-1]>d&&sz[xb+2]-sz[xb+1]<=d&&sz[xb+2]-sz[xb]>d) ans++;
				}
			} 
			else break;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
