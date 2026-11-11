#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+20;
const ll M=3e5+20;
ll last[N];
ll h[N];
ll c[N];
ll n,m;
signed main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		last[c[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ll num=i;
		while(num<=n){
			num=last[c[num]];
			h[c[num]]++;
			num++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}
