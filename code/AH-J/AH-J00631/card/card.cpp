#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f[300010];
ll a[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	vector<ll>v;
	for(ll ti=1;ti<=n;ti++){
		memset(f,0,sizeof f);
		v.clear();
		for(ll i=ti;i<=n;i++){
			if(f[a[i]]){
				while(!v.empty() && v.back()!=a[i]){
					f[v.back()]=0;
					v.pop_back();
				}
			}else{
				f[a[i]]=1;
				v.push_back(a[i]);
			}
		}
		ll len=v.size();
		for(ll i=0;i<len;i++) cnt[v[i]]++;
	}
	for(ll i=1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
