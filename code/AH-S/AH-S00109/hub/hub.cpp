#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T;
int n,p;
int ans=0x3f3f3f3f;
vector<int> g[N];
void ts1(){
	ans=0x3f3f3f3f;
	int dis[25];
	for(int k=0;k<(1<<n+1);k+=2){
		if(__builtin_popcount(k)!=p) continue;
		memset(dis,-1,sizeof(dis));
		int cnt=0,s=0;
		for(int i=1;i<=n;i++){
			if((k>>i&1)==0||dis[i]==0) continue;
			cnt++;
			queue<int> q;
			dis[i]=0;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v:g[u]){
					if((k>>v&1)&&dis[v]){
						dis[v]=0;
						q.push(v);
					}
				}
			}
		}
		if(cnt>2) continue;
		queue<int> q;
		for(int i=1;i<=n;i++) if((k>>i&1)) q.push(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:g[u]){
				if(dis[v]==-1){
					dis[v]=dis[u]+1;
					s=max(s,dis[v]);
					q.push(v);
				}
			}
		}
		ans=min(ans,s);
		/*if(s==1){
			for(int i=1;i<=n;i++)
				if((k>>i&1)) cerr<<i<<'\n';
			for(int i=1;i<=n;i++)
				cerr<<i<<' '<<dis[i]<<'\n';
			cerr<<'\n';
		}*/
	}
	cout<<ans<<'\n';
}
void ts2(){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>p;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n<=10) ts1();
		else if(p==2) ts2();
	}
	return 0;
}
