#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n; i>=1; i--)
		s[i]=s[i+1]+a[i]-a[1];
	for(int i=1; i<=n; i++)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((i-mid)*(a[i]-a[1])-(s[mid]-s[i])<=m) r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}
