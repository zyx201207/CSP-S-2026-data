#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll a[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	vector<ll> v;
	for(ll s=0;s<n;s++){
		v.clear();
		for(ll i=s;i<=n;i++){
			bool f=1;
			ll p;
			for(ll j=0;j<ll(v.size());j++){
				if(v[j]==a[i]) f=0,p=j;
			}
			
			if(f) v.push_back(a[i]);
			else{
				v.erase(v.begin()+p+1,v.end());
			}
			
			for(ll j=0;j<ll(v.size());j++){
				cnt[v[j]]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
