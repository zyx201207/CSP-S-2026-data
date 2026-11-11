#include<bits/stdc++.h>
using namespace std;
int n,C,T,dc[4005],dis[4005],k,u,v,A,B,mx,ans,ANS;
vector<int>g[4005];
queue<int>q;
void bfs(){
	memset(dis,0xff,sizeof(dis));
	memset(dc,0,sizeof(dc));
	mx=0;
	q.push(A);
	q.push(B);
	dis[A]=dis[B]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]!=-1)continue;
			dis[v]=dis[u]+1;
			dc[dis[v]]++;
			mx=max(mx,dis[v]);
			q.push(v);
		}
	}
}
void run(){
	ANS=INT_MAX;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	k-=2;
	for(A=1;A<=n;A++){
		for(B=A+1;B<=n;B++){
			bfs();
			ans=mx;
			for(int i=1;i<=mx;i++){
				if(k>=dc[i]){
					k-=dc[i];
					ans--;
				}else break;
			}
			ANS=min(ANS,ans);
		}
	}
	cout<<ANS<<'\n';
}
int main(){
	// 18:17 30pts!!
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)run();
}
