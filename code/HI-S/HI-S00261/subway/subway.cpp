#include<bits/stdc++.h>
#define ll long long
#define l int
using namespace std;
l MAX_L=214748347;
ll c,n,m,d,q;
ll ww[100010];
struct subw{
	ll v,w;
	bool operator <(const subw& yyy)const{
		return w>yyy.w;
	}
}x;
struct node{
	ll v,w;
}xx;
ll line[500010][2];
priority_queue<subw>p[500010];
priority_queue<subw>p2;
ll dp[5000001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&ww[i]);
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>line[j][0]>>line[j][1];
		}
		for(ll j=1;j<=k-1;j++){
			for(ll j_prew=j+1;j_prew<=k;j_prew++){
				x.v=line[j][0];
				x.w=line[j][1]+line[j_prew][1];
				p[line[j_prew][0]].push(x);
				x.v=line[j_prew][0];
				p[line[j][0]].push(x);
			}
		} 
	}
	for(ll i=1;i<=q;i++){
		ll start_u,end_v;
		ll ans=ww[start_u]+ww[end_v];
		scanf("%lld %lld",&start_u,&end_v);
		x.v=start_u;
		x.w=0;
		p2.push(x);
		for(ll i=1;i<=m;i++){
			dp[i]=MAX_L;
		}
		dp[start_u]=0;
		while(!p2.empty()){
			x=p2.top();
			if(dp[x.v]<x.w)continue;
			for(ll i=0;i<p[x.v].size();i++){
				subw yy;
				yy=p[x.v].top);
				p[x.v].pop()
				if(yy.w<dp[yy.v]){
					p2.push(yy);
				}
			}
		}
		cout<<dp[end_v]<<endl;
	}
	return 0;
}

