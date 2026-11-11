#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
//head
const int N=5e5+5;
ll a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,x=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) x=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-x+1);
	}
	cout<<ans<<'\n';
}
