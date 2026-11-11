#include<bits/stdc++.h>
#define N 1010000
#define ll long long
using namespace std;
ll n,m,a[N],cnt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=1;
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1,sum=m;
		for(ll i=mid-1;i>=1;i--){
			if(sum>=a[mid]-a[i]){
				sum=sum-a[mid]+a[i];
				cnt[mid]++;
			}else break;
		}
		if(cnt[mid]<mid){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=max(cnt[i],ans);
	}
	cout<<ans;
	return 0;
}//2fen
