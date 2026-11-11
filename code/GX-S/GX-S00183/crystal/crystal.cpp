#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll n,m;
ll a[N];
bool vis[N];
bool isdc = 1;
ll ans;
ll pre[N];
bool check(int x){
	ll usage = 0;
	for(ll j = x-1;j>=1;j--){
		usage += (a[x] - a[j]);	
	}
	if(usage > m)return 0;
	return 1;
}
void bl(){
	ll l = 1,r = n,mid = (l + r)/2LL;
	while(l < r){
		mid = (l + r)/2LL;
		if(!check(mid)){
			r = mid-1;
		}else{
			ans = max(ans,mid);
			l = mid+1;
		}
	}
	if(check(mid))ans = max(ans,mid);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	ll d = 0;
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i == 2)d = a[2] - a[1];
		else if(i >= 2){
			if(a[i] - a[i-1]!=d)isdc = 0;
		}
	}
	if(m <= d){
			printf("%d",1);
			return 0;
	}
	if(isdc){
		for(ll i = 2;i<=n;i++){
			if(d * (i-1) > m){
				printf("%lld",i - 1);
				return 0;
			}
		}
		printf("%lld",n);	
	}else{
		sort(a+1,a+n+1);
		bl();
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
