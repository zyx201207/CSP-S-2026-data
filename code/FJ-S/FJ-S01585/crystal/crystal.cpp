#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int n;
ll m,a[N],b[N];
ll ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll dif=a[2]-a[1];
	bool flag=1;
	for(int i=2; i<=n; i++)
	{
		if(a[i]-a[i-1]!=dif)
		{
			flag=0;
			break;
		}
	}
	for(int i=1; i<=n; i++)
	{
		b[i]=a[i];
	}
	ans=n-(unique(b+1,b+n+1)-b-1)+1;
	if(flag)
	{
		ll cost=0,res=1;
		for(int i=2; i<=n; i++)
		{
			cost+=dif*(i-1);
			if(cost>m) break;
			a[1]=a[i];
			res++;
		}
		cout<<res;
	}
	else
	{
		ll cost=0,res=1;
		for(int i=1; i<=n; i++)
		{
			cost=0,res=1;
			for(int j=i-1; j>=1; j--)
			{
				cost+=a[i]-a[j];
				if(cost>m) break;
				res++;
			}
			ans=max(ans,res);
		}
		for(int i=1; i<=n; i++)
		{
			cost=0,res=1;
			for(int i=1; i<=n; i++) b[i]=a[i];
			for(int j=i+1; j<=n; j++)
			{
				cost+=(b[j]-b[i])*(j-i);
				if(cost>m)
				{
					break;
				}
				b[i]=b[j];
				res++;
			}
			ans=max(ans,res);
		}
		cout<<ans;
	}
	return 0;
}