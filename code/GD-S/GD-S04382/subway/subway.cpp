#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,k,gp2,tim2,l,r;
struct node{
	ll w;
	ll st[555];
}cc[222222];
vector<int>tr[555];
void solve(ll l,ll r){
	ll ans=0;
	ans=cc[l].w;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>cc[i].w;
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll u=1;u<=k;u++){
			cin>>gp2>>tim2;
			tr[i].push_back(gp2);
			cc[gp2].st[i]=tim2;
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>l>>r;
		solve(l,r);
	}
}
