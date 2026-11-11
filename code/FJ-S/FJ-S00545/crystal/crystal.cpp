#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500005],sum[500005];

bool ck(ll x){
	for(ll i=1;i<=n-x+1;i++){
		ll j=i+x-1;
		if((j-i)*a[j]-sum[j-1]+sum[i-1]<=m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll lt=1,rt=n,mid;
	while(lt<rt){
		mid=(lt+rt+1)/2;
		if(ck(mid)) lt=mid;
		else rt=mid-1;
	}
	cout<<lt;
	return 0;
} 
