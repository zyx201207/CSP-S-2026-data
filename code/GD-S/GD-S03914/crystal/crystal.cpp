#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		s+=(a[r]-a[r-1])*(r-l+1);
		if(s>m){
			s-=a[r]-a[l];
			l++;
		}
		r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
