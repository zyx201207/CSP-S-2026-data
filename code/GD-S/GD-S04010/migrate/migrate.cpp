#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
long long n,d;
long long ans=0;
long long dis[N];
long long vis[N];
void bfs(int st){
	queue<int>q;
	q.push(st);
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=u+1;j<=n;j++){
			if(x[j]-x[u]<=d){
				if(dis[j]>dis[u]+1){
					vis[j]=vis[u];
					dis[j]=dis[u]+1;
					q.push(j);
				}
				else if(dis[j]==dis[u]+1){
					vis[j]+=vis[u];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==2) ans++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
