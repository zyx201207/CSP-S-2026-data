#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200005];
ll box[105];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll sum=m;
			ll cnt=i;
			for(int j=i;j>=1;j--)
			{
				if(a[i]-a[j]<=sum)sum-=(a[i]-a[j]);
				else
				{
					cnt=i-j;
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	bool shi=true;
	int flag=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=flag)
		{
			shi=false;
			break;
		}
	}
	if(shi){
		ll x=sqrt((2*m)/flag);
		if(x*(x+1)==(2*m)/flag)x++;
		cout<<min(n,x);
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			box[a[i]]++;
		}
		ll ans=0;
		for(int i=1;i<=100;i++)
		{
			ll cnt=box[i];
			ll sum=m;
			for(int j=i-1;j>=1;j--)
			{
				if(box[j]*(i-j)>sum)
				{
					cnt+=(sum/(i-j));
					break;
				}
				else
				{
					cnt+=box[j];
					sum-=(box[j]*(i-j));
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}		
