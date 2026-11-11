#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
using namespace std;
int n;
const int N=5e5+10;
ull m,pre[N],sub[N];
ll a[N];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll maxn=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if((maxn*n-sum)<=m){cout<<n;return 0;}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--){
		sub[i]=a[n]-a[i];
		pre[i]=pre[i+1]+sub[i];
	}
	ll ans=1;
	for(int i=n;i>=1;i--){
		ll l=0,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			ull now=pre[mid]-pre[i+1]-sub[i]*(i-mid+1);
			if(now<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		if(pre[r]-pre[i+1]-sub[i]*(i-r+1)<=m){
			ans=max(ans,i-r+1);
		}
	}
	cout<<ans;
}
