#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],l=1,r,tot=0,ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		tot+=(i-1)*(a[i]-a[i-1]);
		if(tot>m){
			r=i-1,tot-=(i-1)*(a[i]-a[i-1]);
			break;
		}
	}
	ans=r;
	for(int i=r+1;i<=n;i++){
		tot+=(i-l)*(a[i]-a[i-1]);
		while(tot>m){
			tot-=(a[i]-a[l]),l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
