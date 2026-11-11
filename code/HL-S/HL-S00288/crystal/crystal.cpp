#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l,r,w[500010],sum[500100],f[500010],mid,ans;
bool cmp(ll a,ll b){
	return a<b;
}
bool A=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	r=n;
	cin>>w[1],cin>>w[2];
	sum[1]=w[1],sum[2]=w[2]+w[1];
	for(int i=3;i<n+1;i++){
		cin>>w[i];
		if(w[i]-w[i-1]!=w[i-1]-w[i-2]){
			A=0;
		}
	}
	if(A){
		ll num=0;
		ll zz=w[2]-w[1];
		for(int i=1;i<n+1;i++){
			num+=(i*zz);
			if(num>k){
				cout<<i-1;
				break;
			}
		}
		return 0;
	}
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<n+1;i++){
		sum[i]=w[i]+sum[i-1];
	}
	r=n;
	while(r>l){
		bool rr=0;
		mid=(l+r)/2;
		for(int i=mid;i<n+1;i++){
			ll x=(mid-1)*w[i]-(sum[i-1]-sum[i-mid]);
			if(x<=k){
				ans=mid;
				l=mid+1;
				rr=1;
				break;
			}
		}
		if(!rr){
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
//I have a magical idea but it seems hopeless.
