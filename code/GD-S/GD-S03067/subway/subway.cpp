#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],dis[500505],vis[500505];
struct T{
	ll v,w;
	friend bool operator < (T a,T b){
		return a.w>b.w;
	}
};
vector<T> a[500505];

void sv(){
	ll x,y;
	cin>>x>>y;
	dis[x]=0;
	for(int i=1;i<=m+n;i++){
		if(i!=x)dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	priority_queue<T> q;
	q.push({x,0});
	while(!q.empty()){
		ll t=q.top().v;
		q.pop();
		//cout<<t<<' '<<dis[t]<<endl;
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=0;i<(ll)a[t].size();i++){
			ll v=a[t][i].v,w=a[t][i].w;
			dis[v]=min(dis[v],dis[t]+w);
			if(!vis[v]) q.push({v,dis[v]});
		}
	}
	cout<<dis[y]+w[x]+w[y]<<endl;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//m+i作为线路节点 
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll ca,ct;
			cin>>ca>>ct;
			//cout<<ca<<' '<<m+i<<' '<<ct<<endl;
			a[ca].push_back({m+i,ct});
			a[m+i].push_back({ca,ct});
		}
	}
	for(int i=1;i<=q;i++){
		sv();
	}
	return 0; 
}
