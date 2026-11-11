#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
ll n,m;
const int MAXN=5e5+10;
ll a[MAXN],diff[MAXN],minn=1e18,maxn,anss,ans;

signed main()
{
	fre();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int pr=1;
	ll delta=0;
	for(int i=2;i<=n;i++)
	{
		delta+=1ll*(i-pr)*(a[i]-a[i-1]);
		while(delta>m)
		{
			delta-=a[i]-a[pr];
			pr++;
			if(pr==i)
			{
				break;
			}
		}
		ans=max(ans,i-pr+1);
	}
	cout<<ans;
	
	return 0;
}
