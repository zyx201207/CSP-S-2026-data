#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin>>n;
	int ans=0,L=0;
	vector<pair<int,char>> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second,L+=a[i].first;
	int l=1,r=n;
	while(l<r){
		int sz=min(a[l].first,a[r].first);
		a[l].first-=sz,a[r].first-=sz;
		if(a[l].second!=a[r].second) ans+=sz;
		if(a[l].first<=0) l++;
		if(a[r].first<=0) r--;
	}
	cout<<ans;
	return 0;
}
