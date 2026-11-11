#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int dis[N];
bool vis[N];
vector<int>G[N],T[N];
int c,t,n,k;
void dij(int start){
	queue<int>q;
	q.push(start);
	vis[start]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i],w=1;
			if(dis[v]>dis[u]+w){
				dis[v]=min(dis[u]+w,dis[v]);
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
bool check(int mid){
	int f[N]={0};
	for(int i=1;i<=n;i++)f[i]=f[i-1]+dis[i];
	return dis[n]<=mid;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;i++)dij(i);
		int maxx=0;
		for(int i=1;i<=n;i++)maxx=max(maxx,dis[i]);
		int l=0,r=maxx,mid,ans;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10



*/
