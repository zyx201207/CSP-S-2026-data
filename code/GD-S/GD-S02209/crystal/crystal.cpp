#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+100;
int n,m;
int a[maxn],s[maxn];
int ans;
bool check(int x,int y)
{
	int sum=(y-x+1)*a[y]-(s[y]-s[x-1]);
	if(sum<=m) return true;
	return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid,i))
			{
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
} 
