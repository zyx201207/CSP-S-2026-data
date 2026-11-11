#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx=0;
ll n,m;
vector<ll> v(500005);
struct node{
	ll w,num;
}a[500005];

bool cmp(node x,node y){
	return x.num<y.num;
}
bool ccmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i].w);
		a[i-1].num=a[i].w-a[i-1].w;
	}
	sort(a+1,a+1+n,cmp);
	ll ii=1;
	while(m--){
		++a[1].w;
		if(a[1].w>a[2].w){
			sort(a+1,a+1+n,cmp);
		}
	}
	for(ll i=1;i<=n;++i){
		v[a[i].w]++;
	}
	sort(v.begin(),v.end(),ccmp);
	
	printf("%lld",v[0]);
	return 0;
}
