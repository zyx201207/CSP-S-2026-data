#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[300005];

vector<ll> q(500005);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll p=m;
	while(n--){
	ll t=0;
	bool c[300005]={false};
	while(t<=n){
		t++;
		if(c[a[t]]==true){
			while(q.back()!=a[t]){
				ll op=q.back();
				c[op]=false;
				q.pop_back();
			}
			q.push_back(a[t]);
		}else{
			c[a[t]]==true;
			q.push_back(a[t]);
		}
	}
	for(ll i=1;i<=p;i++){
		if(c[i]==true){
			b[i]++;
		}
	}
}
for(ll i=1;i<=p;i++){
	cout<<b[i]<<" ";
}
	return 0;
}
