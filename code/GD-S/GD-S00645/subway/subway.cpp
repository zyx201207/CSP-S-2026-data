#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct edge{
	ll to;
	ll time;
	ll this_to_time;
};

ll c,n,m,d,q;
vector<edge> ve[500005];
ll a[500005],b[500005];
ll w[500005];
ll vis[500005],dis[500005];

void D(ll start,ll end){
	if(start==end){
		return;
	}
	for(edge id:ve[start]){
		if(!vis[id.to]){
			ll to=id.to, time=id.time, this_to_time=id.this_to_time;
			vis[to]=1;
			
			dis[to]=min(dis[to], dis[start]+time+this_to_time);
			//cout<<start<<"<->"<<to<<"---"<<dis[start]<<" "<<dis[to]<<endl;
			D(to,end);
			vis[id.to]=0;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=2*k;j++){
			if(j&1) cin>>a[(j+1)/2];
			else cin>>b[(j+1)/2];
		}
		for(ll l=1;l<k;l++){
			for(ll q=l+1;q<=k;q++){
				ve[a[l]].push_back({a[q],b[q],b[l]});
				ve[a[q]].push_back({a[l],b[l],b[q]});
			}
		}
	}
	/*
	for(ll i=1;i<=m;i++){
		for(auto id:ve[i]){
			cout<<"("<<i<<")*"<<"<|"<<id.to<<"|,"<<id.time<<","<<id.this_to_time<<">--"; 
		}cout<<"\n";
	}
	*/
	while(q--){
		ll start,end;
		cin>>start>>end;
		for(ll i=1;i<=m;i++) dis[i]=1e9;
		memset(vis,0,sizeof vis);
		dis[start]=0;
		vis[start]=1;
		D(start,end);
		
		cout<<dis[end]+w[start]+w[end]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
