#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[300010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	vector<ll> cur;
	for(ll T=1;T<=n;T++){
		cur.clear();
		for(ll i=T;i<=n;i++){
			if(cur.empty()) cur.push_back(a[i]);
			else{
				bool ok=false,pos=0;
				for(ll j=0;j<ll(cur.size());j++){
					if(cur[j]==a[i]){
						ok=1;
						pos=j;
						break;
					}	
				}	
				if(ok) cur.erase(cur.begin()+pos,cur.end());
				cur.push_back(a[i]);
			}	
		}
		for(ll x:cur) cnt[x]++;	
	}	
	for(ll i=1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
