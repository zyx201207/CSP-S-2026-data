#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int a[M],dis[M];
int c,t,n,d;
vector<int>e[M];
struct node{
	int id,stp;
}; 
int dij(int sx,int y){
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=-1;
	q.push(sx);
	dis[sx]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v : e[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[y];
}
int cl(int x,int y){
	int mn=dij(x,y);
	queue<node> q;
	q.push({x,0});
	dis[x]=0;
	int cnt=0;
	while(!q.empty()){
		node tm.id=q.front();q.pop();
		int u=tm.id,step=tm.stp;
		if(u==y&&step==mn){
			cnt++;
			continue;
		}
		for(auto v:e[u]){
			q.push({v,stp+1});
		}
	}	
	return cnt;
}

void solve(int n){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cl(i,j)==2) ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t; 
	for(int i=1;i<=n;i++) {
		e[i].clear();
		cin>>a[i];
	} 
	while(t--){
		cin>>n>>d; 
		if(a[i]<=0){
			int d=(1-a[i]);
		for(int i=1;i<=n;i++) a[i]+=d;
		}
		for(int i=1;i<=n;i++){
			for(int j=1+1;j<=n;j++){
				if(a[j]-a[i]<=d) e[i].push_back(j);
			}
		}
		solve(n);
	} 
	
	return 0;
}
