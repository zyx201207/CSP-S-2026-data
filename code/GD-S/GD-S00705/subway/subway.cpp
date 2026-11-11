#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
ll w[200000];
int g[20004][20004];
ll dij(int s,int t){
	ll dist[m+1];
	bool vis[m+1];
	for(int i=0;i<=m;i++){
		dist[i]=(ll)1e17;
		vis[i]=false;
	}
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(int v=1;v<=m;v++){
			if(g[u][v]==0)continue;
			if(vis[v])continue;
			q.push(v);
			dist[v]=min(dist[v],dist[u]+g[u][v]);
		}
	}
	return dist[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k+1],t[k+1];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int j1=1;j1<=k;j1++){
				if(j==j1)continue;
				g[a[j]][a[j1]]=t[j]+t[j1];
				g[a[j1]][a[j]]=t[j]+t[j1];
			}
		}
	}
	int s,t;
	while(q--){
		cin>>s>>t;
		cout<<dij(s,t)+w[s]+w[t]<<endl;
	}
	return 0;
}

