#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt[300005];
bool fa=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]) fa=false;
	}
	if(fa){
		for(ll i=1;i<=n;i++) cnt[a[i]]++;
		for(ll i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(ll i=1;i<=m;i++) printf("%lld ",cnt[i]);
		printf("\n");
		return 0;
	}
	for(ll t=1;t<=n;t++){
		vector<bool> f(m+5);
		vector<ll> v;
		for(ll i=t;i<=n;i++){
			auto f=find(v.begin(),v.end(),a[i]);
			if(f!=v.end()) v.erase(f,v.end());
			v.push_back(a[i]);
		}
		for(auto s:v) 
			if(!f[s]) cnt[s]++,f[s]=true;
	}
	for(ll i=1;i<=m;i++) printf("%lld ",cnt[i]);
	printf("\n");
	return 0;
}
