#include<bits/stdc++.h>
using namespace std;
long long a[200005],s,t,dis[200005],vis[200005];
long long xu[200005],xv[200005];
struct node{
	long long to,w;
};
vector<node> g[200005];
struct Node{
	long long d,u;
	bool operator >(const Node& x)const{
		return x.d<d;
	}
};
void dij(){
	priority_queue<Node,vector<Node>,greater<Node>> q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		auto t1=q.top();
		q.pop();
		long long d=t1.d,u=t1.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:g[u]){
			long long v=i.to,w=i.w;
			if(dis[v]>d+w){
				dis[v]=d+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k==1){
			int l,r;
			cin>>l>>r;
			continue;
		} 
		else{
			for(int j=1;j<=k;j++){
				cin>>xu[j]>>xv[j];
			}
			for(int j=1;j<=k;j++){
				for(int k1=j+1;k1<=k;k1++){
					g[xu[j]].push_back({xu[k1],xv[j]+xv[k1]});
					g[xu[k1]].push_back({xu[j],xv[j]+xv[k1]});
					//cout<<xu[j]<<" "<<xu[k1]<<" "<<xv[j]+xv[k1]<<endl;
				}
			}
		}
	}
	while(q--){
		cin>>s>>t;
		for(int i=1;i<=m;i++){
			dis[i]=INT_MAX;
			vis[i]=0;
		}
		dij();
		cout<<dis[t]+a[s]+a[t]<<endl;
	}
	return 0;
} 
