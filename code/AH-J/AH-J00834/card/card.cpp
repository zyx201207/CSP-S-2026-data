#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],cnt[300005],cs[300005],ans[300005];
bool f[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,x;
	cin>>n>>x;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cs[a[i]]++;
	}
	for(ll i=1;i<=n;i++){/*
		ll pos=0;
		bool ok=0;
		for(ll j=i+1;j<=n;j++){
			if(a[j]==a[i]) ok=1;
		}
		if(ok) continue;
		memset(cnt,0,sizeof cnt);
		for(ll j=1;j<i;j++) cnt[a[j]]++;
		for(ll j=1;j<i;j++) if(cnt[a[j]]!=cs[a[j]]) pos=j;
		ans[a[i]]+=i-pos;*/
		memset(f,0,sizeof f);
		vector<ll> v;
		for(ll j=i;j<=n;j++){
			if(f[a[j]]){
				while(!v.empty()&&v[v.size()-1]!=a[j]){
					v.pop_back();
				}
			}
			else{
				f[a[j]]=1;
				v.push_back(a[j]);
			}
		}
		ll m=v.size();
		for(ll j=0;j<m;j++){
			cnt[v[j]]++;
		}
	}
	for(ll i=1;i<=300000;i++){
		if(cnt[i]) cout<<cnt[i]<<" ";
	}
	return 0;
}
