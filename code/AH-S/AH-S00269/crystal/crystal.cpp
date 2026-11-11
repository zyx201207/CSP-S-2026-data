#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],p,cnt,ans;
ll l,r,mid,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		if(i!=1&&a[i]==a[i-1]) continue;
		cnt=1;
		for(ll j=i+1;j<=n;j++){
			if(a[j]==a[i]) cnt++;
			else break;
		}
		l=1;
		r=i;
		while(l<r){
			mid=(l+r)>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,cnt+i-l);
	}
	cout<<ans;
	return 0;
}
