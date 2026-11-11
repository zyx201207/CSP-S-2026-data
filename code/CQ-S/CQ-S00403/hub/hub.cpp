#include<bits/stdc++.h>
using namespace std;

#define sht short
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define xwy114514 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll INTINF=0x7f7f7f7f;
const ll LONGINF=0x3f3f3f3f3f3f3f3f;

const ll N=1e6+10;

ll c,T; 
ll n,k;
vector<ll>e[N];
ll flag13[N],dis13[N],vis13[N],fa[N];

ll find(ll x){return fa[x]=fa[x]==x?x:find(fa[x]);}

void add_pair_e(ll u,ll v){
	e[u].push_back(v),e[v].push_back(u);
}

void solve13(){
	cin>>n>>k;
	ll ans=LONGINF;
	for(ll i=1;i<=n;i++)e[i].clear();
	for(ll i=1,u,v;i<n;i++)cin>>u>>v,add_pair_e(u,v);
	for(ll zy=0ll;zy<(1<<n);zy++){
		ll cnt=0ll;
		for(ll i=1;i<=n;i++){
			if((zy>>(i-1))&1)cnt++,flag13[i]=1;
			else flag13[i]=0ll;
		}
		if(cnt!=k)continue;
		for(ll i=1;i<=n;i++)fa[i]=i;
		ll lian=cnt;
		for(ll u=1;u<=n;u++){
			for(ll j=0;j<e[u].size();j++){
				ll v=e[u][j];
				if(flag13[u]&&flag13[v]){
					ll fu=find(u),fv=find(v);
					if(fu!=fv)lian--;
					fa[fu]=fv;
				}
			}
		}
		if(lian>2ll)continue;
		priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> >>pq;
		for(ll i=1;i<=n;i++)dis13[i]=LONGINF,vis13[i]=0ll;
		for(ll i=1;i<=n;i++)if(flag13[i])pq.push({0ll,i}),dis13[i]=0ll;
		while(pq.size()){
			ll u=pq.top().second;pq.pop();
			if(vis13[u])continue;vis13[u]=1ll;
			for(ll i=0;i<e[u].size();i++){
				ll v=e[u][i];
				if(dis13[v]>dis13[u]+1ll){
					dis13[v]=dis13[u]+1ll;
					pq.push({dis13[v],v});
				}
			}
		}
		ll res=-LONGINF;
		for(ll i=1;i<=n;i++)res=max(res,dis13[i]);
		ans=min(ans,res);
	}
	cout<<ans<<endl;
}

void solve13T(){
	while(T--)solve13();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	xwy114514;
	
	cin>>c>>T;
	if(1<=c&&c<=3)solve13T();
	
	return 0;
}
/*
1 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


123可以直接状压
7 可以直接枚举
3*5=15 239 我觉得可以了 
*/
