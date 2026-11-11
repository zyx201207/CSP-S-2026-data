#include<bits/stdc++.h>
using namespace std;
struct edge{
	int d,tdt,tingt,w;
	bool operator<(const edge &x)const{
		return tingt>x.tingt;
	}
};
int dist[500500];
bool vis[500500];
int a[500500],b[500500],ti[500500];
int s,e;
int c,n,m,d,q;
vector<edge>t[500500];
priority_queue<edge>qq;
void dd(){
	for(int i=1;i<=m;i++)dist[i]=INT_MAX;
	dist[s]=a[s]+ti[s];
	qq.push({s,a[s],ti[s],a[s]+ti[s]});
	int flag=1,flag2=1;
	while(!qq.empty()){
		int u=qq.top().d;
		int u1=qq.top().tingt;
		qq.pop();
		if(vis[u])continue;
		vis[u]=1;
//		for(auto v:t[u]){
//			if(dist[v]>(dist[u]+u1*2){
//				
//			}
//		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>ti[j];
		}
		for(int j=1;j<=k;j++){
			if(j<k){
				t[b[j]].push_back({b[j+1],a[b[j]],ti[j],a[b[j]]+ti[j]});
				t[b[j+1]].push_back({b[j],a[b[j+1]],ti[j+1],a[b[j+1]]+ti[j+1]});
			}
		}
	}
	while(q--){
		if(m==1){
			cout<<0<<endl;
		} 
		cin>>s>>e;
		dd();
	}
	return 0;
}
