#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[300010],a[200010],p1[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll cnt=0,t=n;
	while(t--&&t>=0){
		vector<ll> v;map<ll,ll> mp;
		for(ll i=1+cnt;i<=n;i++){
			v.push_back(a[i]);
		}
		for(ll i=1+cnt;i<=n;i++){
			if(p[a[i]]!=0&&v[p[a[i]]-1-cnt]!=0){
				for(ll j=p[a[i]];j<i;j++) v[j-1-cnt]=0;
			}
			p[a[i]]=i;
		}
		cnt++;
		ll len=v.size();
		for(ll i=0;i<len;i++){
			if(v[i]!=0) p1[v[i]]++;
		}
	}
	for(ll i=1;i<=m;i++) cout<<p1[i]<<" ";
	return 0;
}
