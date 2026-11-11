#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.begin()+1+n);
	int ans=0,sum=0;
	int l=1,r=1;
	for(;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
