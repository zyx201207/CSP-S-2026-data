#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long lll;
typedef pair<lll,ll> pll;
const ll maxm=5e5+5,maxn=5e2+5;
ll c,n,m,d,Q,x,y,w[maxm],hc[maxm][maxn],flag;
lll dis[maxn][maxn],ans,tmp;
vector<ll> hcc[maxm];
bool vis[maxn];
priority_queue<pll,vector<pll>,greater<pll>> q;
struct node{
	ll to;
	lll val;
};
vector<node> e[maxn];
void dijstra(ll s){
	q=priority_queue<pll,vector<pll>,greater<pll>>();
	for(ll i=0;i<=n;i++){
		dis[s][i]=LLONG_MAX;
		vis[i]=false;
	}
	q.push({0,s});
	dis[s][s]=0;
	while(!q.empty()){
		ll nw=q.top().second;
		q.pop();
		if(!vis[nw]){
			vis[nw]=true;
			for(auto i:e[nw]){
				ll nxt=i.to;
				lll v=i.val;
				if(dis[s][nxt]>dis[s][nw]+v){
					dis[s][nxt]=dis[s][nw]+v;
					q.push({dis[s][nxt],nxt});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll kkk;
		cin>>kkk;
		for(ll j=1;j<=kkk;j++){
			ll to,sj;
			cin>>to>>sj;
			hc[to][i]=sj;
			hcc[to].push_back(i);
		}
	}
	for(ll i=1;i<=m;i++){
		if(hcc[i].size()>1){
			for(ll j=0;j<hcc[i].size();j++){
				for(ll k=j+1;k<hcc[i].size();k++){
					ll frm=hcc[i][j],tooo=hcc[i][k],juli=hc[i][frm]+hc[i][tooo];
					e[frm].push_back({tooo,juli});
					e[tooo].push_back({frm,juli});
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		dijstra(i);
	}
	for(ll p=1;p<=Q;p++){
		cin>>x>>y;
		flag=0;
		ans=LLONG_MAX;
		for(auto j:hcc[x]){
			for(auto k:hcc[y]){
				if(j==k){
					flag=j;
					break;
				}
			}
		}
		if(flag){
			ans=w[x];
			ans+=w[y];
			ans+=hc[x][flag];
			ans+=hc[y][flag];
			cout<<ans<<"\n";
		}else{
			for(auto j:hcc[x]){
				for(auto k:hcc[y]){
					tmp=w[x];
					tmp+=w[y];
					tmp+=hc[x][j];
					tmp+=hc[y][k];
					tmp+=dis[j][k];
					ans=min(ans,tmp);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
