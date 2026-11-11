#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	ll ans=1,sum,k;
	for(ll i=1;i<=n;i++){
		k=m,sum=1;
		for(ll j=i-1;j>=1;j--){
			if(a[i]-a[j]<=k) k-=a[i]-a[j],sum++;
			else break;
		}
		ans=max(ans,sum);
	}cout<<ans;
	return 0;
} 
