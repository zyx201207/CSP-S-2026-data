#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N],ans;
bool check(ll x,ll y){
	ll need=a[y]*(y-x+1)-(sum[y]-sum[x-1]);
	return need<=m;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}	
	cout<<ans; 
	return 0;
}
