#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500000+10],f[300000+10],ans[300000+10];
vector<ll> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		v.clear();
		memset(f,0,sizeof f);
		for(ll j=i;j<=n;j++){
			if(f[a[j]]==1){
				for(ll k=v.size()-1;k>=0;k--){
					if(v[k+1]==a[j]){
						break;
					}
					f[v.back()]=0;
					v.pop_back();
				}
				v.push_back(a[j]);
			}else{
				v.push_back(a[j]);
				f[a[j]]=1;
			}
		}
		for(ll j=0;j<ll(v.size());j++){
			ans[v[j]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
