#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace did
{
	const int N=5e5+5;
	int n,m,a[N];
	bool check(int x)
	{
		int sum=0,minn=1e18;
		for(int i=1;i<=x;i++) sum+=(a[x]-a[i]);
		minn=min(minn,sum);
		//cout<<sum<<" ";
		for(int i=2;i+x-1<=n;i++)
		{
			int y=i+x-1;
			sum=sum-(a[y-1]-a[i-1])+(x-1)*(a[y]-a[y-1]);
			minn=min(minn,sum);
			//cout<<sum<<" ";
		}
		return minn<=m;
	}
	signed main()
	{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) l=mid+1;
			else r=mid-1; 
		}
		cout<<r;
		return 0;
	}
}
signed main()
{
	did::main();
	return 0;
}
