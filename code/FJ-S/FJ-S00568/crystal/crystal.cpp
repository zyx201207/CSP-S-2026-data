#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double 
#define endl "\n" 
int n,m,a[500010],ans,minn=1000000000000000010,b[500010];
bool jc(int jb)
{
	for(int i=jb;i<=n;i++)
	{
		if((jb-1)*a[i]-(b[i-1]-b[i-jb])<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<+n;i++)
    {
    	cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			minn=min(minn,a[i]-a[i-1]);
		}
    	b[i]=b[i-1]+a[i];
	}
	if(minn>m)
	{
		cout << 1;
		return 0;
	}
	int z=1,y=n;
	while(z<=y)
	{
		int mid=(z+y)/2;
		if(jc(mid))
		{
			z=mid+1;
			ans=mid;
		}
		else
		{
			y=mid-1;
		}
	 } 
	cout << ans;
	return 0;
}
