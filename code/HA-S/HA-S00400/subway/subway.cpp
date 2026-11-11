#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define wep(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)
#define tep(a,b) for(auto &(a):(b))
using namespace std;
const ll N=5e5+5;
ll a[N],k[N];
vector<pair<ll,ll> > g[N];
ll dist[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll CCF_is_shu_jv_shan_chu,n,m,d,Q;
	cin>>CCF_is_shu_jv_shan_chu>>n>>m>>d>>Q;
	ll cnt=0; 
	rep(i,1,m){
		cin>>a[i];
	}
	bool flag=1;
	rep(i,1,n){
		cin>>k[i];
		rep(l,1,k[i]){
			ll x,y;
			cin>>x>>y;
			if(!cnt){
				cnt=y;
			}
			else if(cnt!=y){
//				cout<<cnt<<' '<<y<<endl;
				flag=0;
			}
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
		}
	}
	if(flag){
//		cout<<"±ù±ù±ù\n";
		while(Q--){
			ll x,y;
			rep(i,0,n+m+1){
				dist[i]=0;
			}
			cin>>x>>y;
			queue<ll> q;
			q.push(x);
			while(!q.empty()){
				ll tx=q.front();
				q.pop();
				if(tx==y){
					break;
				}
				tep(gh,g[tx]){
					ll ty=gh.first,v=gh.second;
					if(!dist[ty]){
						dist[ty]=dist[tx]+v;
						q.push(ty);
					}
				}
			}
			printf("%lld",dist[y]+a[x]+a[y]);
			putchar('\n');
		}
		return 0;
	}
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	while(Q--){
		rep(i,0,m+n+1){
			dist[i]=1e18;
		}
		ll s,t;
		cin>>s>>t;
		q.push({0,s});
		dist[s]=0;
		while(!q.empty()){
			ll tx=q.top().second,val=q.top().first;
//			cout<<"dist["<<tx<<"]="<<dist[tx]<<endl;
//			if(tx>m){
//				vis[tx-m]=1;
//			}
			q.pop();
			if(dist[tx]<val)
				continue;
			tep(gh,g[tx]){
				ll ty=gh.first,v=gh.second;
//				cout<<"ty="<<ty<<endl;
				if(dist[ty]>dist[tx]+v){
					dist[ty]=dist[tx]+v;
					q.push({dist[ty],ty});
				}
			}
		}
		printf("%lld",dist[t]+a[s]+a[t]);
		putchar('\n');
	}
	return 0;
}
