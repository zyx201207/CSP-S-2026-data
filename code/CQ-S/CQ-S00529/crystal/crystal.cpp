#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n,m;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
	clock_t t0=clock();
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll answer=0;
	for(ll i=1;i<=n;i++){
		ll L=1,R=i;
		while(L<R){
			ll mid=(L+R)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)R=mid;
			else L=mid+1;
		}
		answer=max(answer,i-L+1);
	}
	cout<<answer;
	fprintf(stderr,"time=%.3fs\n",(double)(clock()-t0)/CLOCKS_PER_SEC);
	return 0; 
}
