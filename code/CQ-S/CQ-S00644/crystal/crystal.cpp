#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N],s[N]; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i = 1;i<=n;i++)
		s[i] = s[i-1]+a[i];
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		int l = 1,r = i,res = i;
		while(l<=r)
		{
			int mid = (l+r)/2;
//			cout<<mid<<' '<<i<<":"<<(i-mid+1)*a[i]<<"-"<<s[i]-s[mid-1]<<'\n';
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) res = mid,r = mid-1;
			else l = mid+1;
		}
//		cout<<"xx"<<i<<' '<<res<<'\n';
		ans = max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}

