#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans=1;
ll a[N],pre[N];
ll get(int l,int r){
	return pre[r]-pre[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(ll i=2;i<=n;i++){
		if(a[i]==a[i+1]&&i!=n) continue;
		ll l=1,r=i-1;
		ll res=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll len=(i-mid+1);
			ll cost=(a[i]*len)-get(mid,i);
			if(cost<=m){
				res=max(res,len);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}

