#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=5e5+10;

vector<ll>arr(N,0);
vector<ll>pre(N,0);

ll search(ll m,ll end){
	ll l=1,r=end-1,h=end-1;
	ll mid=(l+r)/2;
	while(l<r){
		ll cost=arr[end]*(h-mid+1)-(pre[h]-pre[mid-1]);
		if(cost<=m){
			r=mid;
		}else{
			l=mid+1;
		}
		mid=(l+r)/2;
	}
	if((arr[end]*(h-mid+1)-(pre[h]-pre[mid-1]))<=m){
		return h-mid+1;
	}else{
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	arr.resize(n+1);
	pre.resize(n+1);
	sort(arr.begin()+1,arr.end());
	for(ll i=1;i<=n;i++){
		pre[i]=arr[i]+pre[i-1];
	}
	ll ans=0;
	for(ll i=2;i<=n;i++){
		ans=max(ans,search(m,i)+1);
	}
	cout<<ans;
	return 0;
}
