#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5+10;
ll a[maxn],pre[maxn];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int res=1;
	for(int i=2;i<=n;i++)
	{
		// 二分查找一个最靠左的使得(r-l+1)*a[i]-(pre[r]-pre[l-1])<=m 的区间
		auto check=[&](int l)
		{
			return (i-l+1)*a[i]-(pre[i]-pre[l-1])<=m;
		};
		int l=1,r=i,ans=i+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) 
			{
				r=mid;
				ans=mid;
			}
			else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
}
