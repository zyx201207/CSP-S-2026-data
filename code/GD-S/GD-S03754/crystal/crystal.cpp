#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500007];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,s,l=1,r=2;
	while(r<=n){
		while(r<=n&&s+(r-l)*(a[r]-a[r-1])<=m){
			s+=(r-l)*(a[r]-a[r-1]);
			r++;
		}
		ans=max(ans,r-l);
		s+=(r-l)*(a[r]-a[r-1]);
		r++;
		while(l<=n&&s-a[r-1]+a[l]>m){
			s=s-a[r-1]+a[l];
			l++;
		}
		s=s-a[r-1]+a[l];
		l++;
	}
	cout<<ans;
}
