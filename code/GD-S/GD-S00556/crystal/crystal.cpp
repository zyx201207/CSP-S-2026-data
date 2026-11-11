#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],s[N],ans=1;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i,res=n+1;
//		cout<<i<<":";
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
			{
//				cout<<mid<<' ';
				r=mid-1;
				res=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
//		cout<<'\n';
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
