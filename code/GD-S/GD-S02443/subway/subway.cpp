#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=501,M=5e5+10;
ll w[N];
struct node{
	ll k,v,t;
}a[M];
bool cmp(node x,node y){
	return x.v<y.v;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++){
			cin>>a[j].v>>a[j].t;
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		ans+=w[x]+w[y];
		cout<<ans;
	}
	return 0;
}
