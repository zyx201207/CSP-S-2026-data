#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define Endl "\n",void()
#define End void()
#define make make_pair
namespace kong{bool st;}
const int N=7*1e5+7;
ll c,n,m,d,q;
ll w[N],vis[N],vis2[N];
struct node{
	ll nxt,to,val;
}e[N*2];
ll cnt=0,head[N],tot=0;
void add(ll x,ll y,ll z){
	e[++cnt]={head[x],y,z};
	return head[x]=cnt,void();
}
void solve(){
	cin>>c>>n>>m>>d>>q,tot=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,to,val;i<=n;i++){
		cin>>k;
		cin>>to>>val;
		tot++;
		add(to,tot,val);
		add(tot,to,val);
		for(int j=2;j<=k;j++){
			cin>>to>>val;
			add(to,tot,val);
			add(tot,to,val);
		}
	}
	while(q--){
		ll s=0,t=0;
		cin>>s>>t;
		deque<pair<ll,ll> > que;
		que.push_back(make(s,0));
		for(int i=1;i<=tot;i++) vis[i]=LLONG_MAX;
		ll ans=LLONG_MAX;
		while(!que.empty()){
			auto now=que.front();
			que.pop_front();
			ll x=now.first,tmp=now.second;
			if(x==t){
				ans=min(ans,tmp);
				continue;
			}
			for(int i=head[x];i;i=e[i].nxt){
				ll y=e[i].to,w=e[i].val;
				if(tmp+w<vis[y]){
					vis[y]=tmp+w;
					que.push_back(make(y,vis[y]));
				}
			}
		}
		cout<<w[s]+w[t]+ans<<endl;
	}
	return;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve(); 
	cerr<<endl<<kong::MB()<<endl;
	return 0;
} 
