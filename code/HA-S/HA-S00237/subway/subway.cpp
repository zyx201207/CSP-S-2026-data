#include<bits/stdc++.h>
using namespace std;

#define ll int
#define foru(a,b,c) for(ll a=b;a<=c;a++)
#define endl "\n"
#define pll pair<ll,ll>

ll c,n,m,d,q;
ll z[500005],dis[500505];
bool vis[500505];
vector<vector<pll > >e(500505),rq(500005);
priority_queue<pll,vector<pll >,greater<pll > >pq;
ll ans[100005],acnt;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    foru(i,1,m){
    	cin>>z[i];
	}
	foru(i,1,n){
		ll k;
		cin>>k;
		foru(j,1,k){
			ll ai,ti;
			cin>>ai>>ti;
			e[ai].push_back({m+i,ti});
			e[m+i].push_back({ai,ti});
		}
	}
	foru(i,1,q){
		ll x,y;
		cin>>x>>y;
		acnt++;
		rq[x].push_back({y,acnt});
	}
	foru(l,1,m){
		if(!rq[l].empty()){
			foru(i,1,n+m){
				dis[i]=1e9;
				vis[i]=0;
			}
			dis[l]=0;
			pq.push({0,l});
			while(!pq.empty()){
				ll u=pq.top().second;
				pq.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(auto g:e[u]){
					ll w=g.second,v=g.first;
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						pq.push({dis[v],v});
					}
				}
			}
			for(auto v:rq[l]){
				ans[v.second]=z[l]+dis[v.first]+z[v.first];
			}
		}
	}
	foru(i,1,acnt){
		cout<<ans[i]<<endl;
	}
    return 0;
}
