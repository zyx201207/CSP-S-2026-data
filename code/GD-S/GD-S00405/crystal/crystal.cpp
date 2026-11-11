#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
int n,ans;
ll m,a[N+5],q[N+5];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1,id=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(q[i]-q[mid-1])<=m) id=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-id+1);
	}
	cout<<ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;//cin>>_;
	while(_--) solve();
	return 0;
}
