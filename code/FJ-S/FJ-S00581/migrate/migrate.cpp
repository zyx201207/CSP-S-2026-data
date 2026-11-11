#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
 	//freopen("migrate.in","r",stdin); 
 	//freopen("migrate.out","w",stdout);
	ll c,t,f=0;
	cin>>c>>t;
	for(ll i=0;i<t;i++)
	{
		f=0;
		ll n,d;
		cin>>n>>d;
		vector<ll>v(n);
		vector<vector<ll>>mi(n,vector<ll>(n));
		for(ll j=0;j<n;j++)cin>>v[j];
		for(ll j=0;j<n-1;j++)
		{	
			for(ll k=j+1;k<n;k++)
			{	
				ll w=1;
				for(ll t=j,s=t+1;s<=k;t++,s++)
				{
					if(v[s]-v[t]>d)
					{
						w=0;
						break;
					}
				}
				mi[j][k]=(v[k]-v[j]+d-1)/d;
				if(mi[j][k]>1&&(v[k]-v[j])%d==1&&(v[k]-v[j])%2!=0&&w==1)
				{
					f++;
					break;
				}
			}
		}
		cout<<f<<endl;
	}
	return 0;
}
