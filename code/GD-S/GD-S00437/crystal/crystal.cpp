#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
int n;
ll m,a[500005];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int lt=1;
	for(int i=1;i<=n;i++){
		ll now=a[i];
		a[i]+=a[i-1];
		while(now*(i-lt+1ll)-(a[i]-a[lt-1])>m&&lt<i){
//			cout<<lt<<" "<<i<<" "<<now<<" "<<now*(i-lt+1ll)<<" "<<a[i]<<" "<<m<<"\n";
			lt++;
		}
//		cout<<a[i]<<" "<<now*(i-lt+1ll)<<"\n";
		ans=max(ans,i-lt+1);
	}
	cout<<ans;
	return 0;
}
