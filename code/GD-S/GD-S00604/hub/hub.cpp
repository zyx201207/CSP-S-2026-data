#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int head[N],nxt[N<<1],to[N<<1];
int cnt;
void add(int u,int v){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
bool inq[N];
int dis[N];
int spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(s);inq[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		int ans=1e6+5;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					memset(inq,0,sizeof(inq));
					spfa(i);
					int min1=1e6+5;
					for(int k=1;k<=n;k++){
						if(k!=i)	min1=min(min1,dis[k]);
					}
					memset(inq,0,sizeof(inq));
					spfa(j);
					int min2=1e6+5;
					for(int k=1;k<=n;k++){
						if(k!=j)	min2=min(min2,dis[k]);
					}
//					cout<<min1<<" "<<min2<<endl;
					ans=min(ans,max(min1,min2));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
