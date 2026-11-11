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
	int cnt1=0,cnt2=a[2]-a[1],f=0;
	for(int i=2;i<n;i++){
		cnt1=a[i+1]-a[i];
		if(cnt1==cnt2) f++;
		cnt2=cnt1;
	}
	if(f==n-1||f==n-2){
		if(cnt2==1){
			int x=n*n/2;
			if(x<m) cout<<n;
			else cout<<2*m/2;
			return 0;
		}
	}
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
