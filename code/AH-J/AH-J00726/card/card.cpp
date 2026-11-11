#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
map<ll,ll> pai,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			p[a[j]]++;
			if(p[a[j]]>1){
				for(ll k=j-1;k>=i;k--){
					p[a[k]]--;
					if(a[k]==a[j]) break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(p[j]==1) pai[j]++;
		}
		p.clear();
	}
	for(int i=1;i<=m;i++) cout<<pai[i]<<" ";
	return 0;
}
