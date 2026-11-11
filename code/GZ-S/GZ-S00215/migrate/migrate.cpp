//GZ-S00215 毕节七星关东辰实验学校 张碧昊 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		ll x[n+2];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		ll c=x[2]-x[1];
		if(d<2*c||d>=3*c||n<4)cout<<0<<endl;
		else
		{
			if(n==4)cout<<1<<endl;
			else
			{
				if(n%2==0)
			{
				ll k=(n-2)*(n-5)/2+(n-2)/2;
				
				cout<<k<<endl;
			}
			else
			{
				ll k=(n-1)*(n-4)/2;
				cout<<k<<endl;
			}
			}
			
		}
	}
	return 0;
}
