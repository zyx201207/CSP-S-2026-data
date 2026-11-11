#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005;
ll n,m;
ll s[N],t[N];
ll vis1[N];
vector<ll> v;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(ll i=1;i<=n;i++){
		v.clear();
		memset(vis1,-1,sizeof vis1);
		for(ll j=i;j<=n;j++){
			if(vis1[s[j]]!=-1){
				for(ll k=v.size()-1;k>=vis1[s[j]];k--) v.erase(v.begin()+k); 
			}
			v.push_back(s[j]);
			vis1[s[j]]=v.size()-1;
		}
		ll len=v.size();
		for(ll j=0;j<len;j++) t[v[j]]++;
	}
 	for(ll i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
