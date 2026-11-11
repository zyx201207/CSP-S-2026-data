#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
map<ll,ll> b;
deque<ll> q;
void ni(ll x){
	for(ll i=x;i<=n;i++){
		bool ok=0;
		for(ll j=0;j<q.size();j++){
			if(q[j]==a[i]){
				while(j<q.size()) q.pop_back();
			}
		}
		q.push_back(a[i]);
	}
	for(auto &k : q){
		b[k]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		q.clear();
		ni(i);
	}
	for(ll i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
