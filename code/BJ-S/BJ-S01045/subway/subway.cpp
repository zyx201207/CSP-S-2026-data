#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,Q;
ll w[500010];
ll a[500010];
ll t[500010];
struct node{
	ll x,id;//v:站厅编号，对应路线
			//e:时间，路线
			//q:=v
	ll rea;//q:ans
};
vector<node>v[500010];//储存每个站厅所可到达的其他站厅的路线
vector<ll>rv[500010];//每个站厅可被经过的路线
vector<node>e[500010];//储存每个站厅可到达的站台
ll rans[500010];//到达展厅的时间
ll st,en,ans;
queue<node>q;
ll que(ll root,ll x){
	ll eid;
	for(ll i=0;i<(ll)e[root].size();i++){
		if(e[root][i].id==x)
		eid=e[root][i].x;
	}
	return eid;
}
void spfa(ll st,ll sid){//所存储的状态，为在站台的时间
	
	for(ll i=1;i<=m;i++)
	rans[i]=1e9;
	rans[st]=w[st];
	while(q.size())q.pop();
	q.push({st,sid,w[st]+que(st,sid)});
	
	while(q.size()){
		
		node t=q.front();
		ll tx=t.x,tid=t.id,reat=t.rea;
		q.pop();
			
		for(ll i=0;i<(ll)v[tx].size();i++){
			if(v[tx][i].id==tid){
				if(reat<=rans[v[tx][i].x]){
					q.push({v[tx][i].x,tid,reat});
					rans[v[tx][i].x]=min(rans[v[tx][i].x],reat+que(v[tx][i].x,v[tx][i].id));
				}
			}else{
				if(reat+que(tx,tid)+que(tx,v[tx][i].id)<=rans[v[tx][i].x]){
					q.push({v[tx][i].x,v[tx][i].id,reat+que(tx,tid)+que(tx,v[tx][i].id)});
					rans[v[tx][i].x]=min(rans[v[tx][i].x],reat+que(tx,tid)+que(tx,v[tx][i].id)+que(v[tx][i].x,v[tx][i].id));
				}
			}
		}
	}
	ans=min(ans,rans[en]+w[en]);
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			e[a[j]].push_back({t[j],i,(ll)1e9});
			rv[a[j]].push_back(i);
		}
		for(ll j=1;j<k;j++)
			v[a[j]].push_back({a[j+1],i,(ll)1e9});
	}
	
	while(Q--){
		cin>>st>>en;
		ans=1e9;
		for(ll i=0;i<(ll)rv[st].size();i++)
			spfa(st,rv[st][i]);
		cout<<ans<<endl;
	}
    return 0;
}
