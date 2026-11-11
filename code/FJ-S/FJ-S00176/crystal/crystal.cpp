#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<x<<"\n";
#define pb push_back
#define bg begin
#define ed end
#define pii pair<int,int>
#define ft first
#define sc second
#define int long long
using namespace std;
typedef long long lli;
typedef double lf;
const int N=5e5+5;
int a[N],d[N],n,m,ans=1;
int sum[N];
bool check(int l,int r)
{
	return a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m;
}
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(i,mid))
				l=mid;
			else
				r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
/*
5 9
-101 -100 -109 100 109
*/
