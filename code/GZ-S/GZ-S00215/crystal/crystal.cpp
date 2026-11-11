//GZ-S00215 毕节七星关东辰实验学校 张碧昊 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
ll n,m;
ll a[600000];
ll lastans=0;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	
	ll op=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=op)
		{
			break;
		}
		if(i==n)
		{
			ll l=1;
			ll r=n;
			while(l<r)
			{
				ll mid=(l+r)/2;
				if(((mid*(mid-1)*op)/2)>m)
				{
					r=mid-1;
				}
				else if(((mid*(mid-1)*op)/2)<m)
				{
					if(((mid*(mid+1)*op)/2)>m)
					{
						cout<<mid<<endl;
						return 0;
					}
					else
					l=mid+1;
				}
				else if(((mid*(mid-1)*op)/2)==m)
				{
					cout<<mid<<endl;
					return 0;
				}
			}
			cout<<l<<endl;
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]>m)continue;
		ll c[n+1];
		ll qwq=1;
		for(int j=1;j<=i;j++)
		{
			if(j==i||a[j]>a[i]||a[i]-a[j]>m)continue;
			c[qwq]=a[i]-a[j];
			qwq++;
			
		}
		sort(c+1,c+qwq);
	
		ll cnt=0;
		ll ans=1;
		for(int j=1;j<qwq;j++)
		{
			if((cnt+c[j])<=m)
			{
				cnt+=c[j];
				ans++;
			}
			else
			{
				break;
			}
		}
		
		lastans=max(lastans,ans);
		
	}
	cout<<lastans<<endl;
	return 0;
}
