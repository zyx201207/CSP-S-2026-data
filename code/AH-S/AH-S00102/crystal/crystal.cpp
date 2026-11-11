#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100010],sum,ok=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]*n-sum<=m){
		cout<<a[n];
		return 0;
	}
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])ok=0;
	}
	if(ok==1){
		ll d=a[2]-a[1],cost=0;
		if(n%2){
			ll l=n/2,r=n/2+2;
			while(l>1&&r<n){
				cost+=d*(n/2+1-l);
				if(cost>m)break;
				l--;
				cost+=d*(r-n*2-1);
				if(cost>m)break;
				r++;
			}
			cout<<r-l+1;
		}
		else{
			ll l=n/2-1,r=n/2+2;
			while(l>1&&r<n){
				cost+=d*(n/2-l);
				if(cost>m)break;
				l--;
				cost+=d*(r-n*2-1);
				if(cost>m)break;
				r++;
			}
			cout<<r-l+1;
		}
	}
	return 0;
}
