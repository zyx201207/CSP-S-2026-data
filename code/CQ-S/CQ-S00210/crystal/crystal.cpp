#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=1;
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		ll l=1,r=i-1,tmp=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-1-mid+1)-(sum[i-1]-sum[mid-1])<=m) tmp=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
} 
