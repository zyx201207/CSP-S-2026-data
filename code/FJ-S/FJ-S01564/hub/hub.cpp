#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>Road[N];
bool mp[N]; 
int dis[N][N];
int getl(int u){
	int ret=0;
	queue<int>q;
	q.push(u);
	while(!q.empty()){
		int head=q.front();q.pop();
		mp[head]=1;
		for(int i:Road[head]){
			if(!mp[i]){
				q.push(i);
				dis[u][i]=min(dis[u][i],dis[u][head]+1);
				ret=max(ret,dis[u][i])
			}
		}
		
	}	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		memset(mp,0,sizeof(mp));
		memset(dis,0x3f3f3f3f,sizeof(dis));
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			Road[u].push_back(v);
			Road[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		int l=0;
		for(int i=1;i<=n;i++){
			l=max(l,getl(i));
		}
		int ans=0;
		while((ans+1)*4+1<=l)ans++;
		cout<<ans;
	}
	return 0;
}
