#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int maxn=5e5+5;
ll n,m,a[maxn],q[maxn],l=1,r,res,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)
	{
		q[++r]=a[i];
		res+=(r-l)*(a[i]-a[i-1]);
		while(res>m)res-=(a[i]-a[l++]);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
