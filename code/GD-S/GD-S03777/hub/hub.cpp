#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y;
int vis[10007],abc[10007],dis[10007],ttt[107];
void bfs2(int x){
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		vector<int> g[1007];
		for(int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(c<=6){
			int ans=1000;
			for(int i=1;i<pow(2,n);i++){
				memset(ttt,0,sizeof(ttt));
				int sum=0,kk=0;
				int tt=i,cnt=0;
				for(int i=0;i<=n;i++){
					if((tt>>i)&1) abc[++kk]=i+1,cnt++,ttt[i]=1;
				}
				if(cnt!=m) continue;
				cnt=0;
				memset(vis,0,sizeof(vis));
				for(int ii=1;ii<=m;ii++){
					if(vis[abc[ii]]) continue;
					cnt++;
					int x=abc[ii];
					queue<int> q;
					q.push(x);
					vis[x]=1;
					while(!q.empty()){
						int x=q.front();
						q.pop();
						for(int kk:g[x]){
							if(vis[kk]) continue;
							if(!ttt[kk]) continue;
							vis[i]=1;
							q.push(i);
						}
					}
				}
				if(cnt>2) continue;
			memset(dis,0x3f3f3f3f,sizeof(dis));
				for(int ii=1;ii<=m;ii++){
					int x=abc[ii];
					queue<int> q;
					q.push(x);
					dis[x]=0;
					while(!q.empty()){
						int x=q.front();
						q.pop();
						for(int i:g[x]){
							if(dis[i]>dis[x]+1)dis[i]=dis[x]+1,q.push(i);
						}
					}
				}
				for(int i=1;i<=n;i++){
					sum=max(sum,dis[i]);
				}
				ans=min(ans,sum);
			}
			cout<<ans<<'\n';
			
		}
		if(c==13||c==14){
			cout<<(n-m*2)/8+2<<endl;
		}
	}
	return 0;
} 
