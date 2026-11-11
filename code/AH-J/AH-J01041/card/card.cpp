#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
vector<ll>v;
ll vi[500005],h[500005];
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll maxn=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(ll i=1;i<=n;i++){
		ll l=0;
		for(ll j=i;j<=n;j++){
			if(!vi[a[j]]){
				vi[a[j]]=j-i;
				v.push_back(a[j]);
				l++;
			}else{
				while(l>vi[a[j]]){
					v.pop_back();
					vi[a[l]]=0;
					l--;
				}
			}
		}
		memset(vi,0,sizeof(vi));
		while(!v.empty()){
			cout<<v.back()<<" ";
			h[v.back()]++;
			v.pop_back();
		}
		cout<<endl;
	}
	for(ll i=1;i<=maxn;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
