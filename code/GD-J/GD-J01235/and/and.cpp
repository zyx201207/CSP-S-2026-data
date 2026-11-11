#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int nn=n;
	vector<ll> a;
	
	while(nn--)
	{
		ll t;
		cin>>t;
		a.push_back(t);
	}
	ll ans=LONG_LONG_MIN;
	if(m==0)
	cout<<0;
	else if(m==1)
	{
		for(int i = 0;i<n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		vector<vector<ll>> _and(n,vector<ll>(n,0));
	for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			if(i!=j)
			_and[i][j]=a[i]&a[j];
			else
			_and[i][j]=LONG_LONG_MIN;
			ans=max(ans,_and[i][j]);
		}
	}
	cout<<ans;
	}
	else if(m==3)
	{
		vector<vector<vector<ll>>> _and(n,vector<vector<ll>>(n,vector<ll>(n,0)));
		for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			for(ll k = 0;k<n;k++)
			{
			if(i!=j&&j!=k&&i!=k)
			_and[i][j][k]=a[i]&a[j]&a[k];
			else
			_and[i][j][k]=LONG_LONG_MIN;
			ans=max(ans,_and[i][j][k]);
			}
		}
	}
	cout<<ans;
	}
	else if(m==4)
	{
		vector<vector<vector<vector<ll>>>> _and(n,vector<vector<vector<ll>>>(n,vector<vector<ll>>(n,vector<ll>(n,0))));
		for(ll i = 0;i<n;i++)
		{
			for(ll j = 0;j<n;j++)
			{
				for(ll k = 0;k<n;k++)
				{
					for(ll l = 0;l<n;l++)
					{
						if(i!=j&&j!=k&&k!=l)
							_and[i][j][k][l]=a[i]&a[j]&a[k]&a[l];
						else
							_and[i][j][k][l]=LONG_LONG_MIN;
						ans=max(ans,_and[i][j][k][l]);
					}
				}
			}
		}
		cout<<ans;
	 } 
	 else if(m==5)
	 {
	 	vector<vector<vector<vector<vector<ll>>>>> _and(n,vector<vector<vector<vector<ll>>>>(n,vector<vector<vector<ll>>>(n,vector<vector<ll>>(n,vector<ll>(n,0)))));
		for(ll i = 0;i<n;i++)
		{
			for(ll j = 0;j<n;j++)
			{
				for(ll k = 0;k<n;k++)
				{
					for(ll l = 0;l<n;l++)
					{
						for(ll o = 0;o<n;o++)
						{
						
							if(i!=j&&j!=k&&k!=l&&l!=o)
								_and[i][j][k][l][o]=a[i]&a[j]&a[k]&a[l]&a[o];
							else
								_and[i][j][k][l][o]=LONG_LONG_MIN;
							ans=max(ans,_and[i][j][k][l][o]);
						}
					}
				}
			}
		}
		cout<<ans;
	 }
	 else{
	 	cout<<0;
	 }
	return 0;
}
