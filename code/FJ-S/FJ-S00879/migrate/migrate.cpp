#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
int c,t,n,d,x[305];
int h[305],to[90005],nxt[90005],cnt=0;
void add(int u,int v){
	to[++cnt]=v;nxt[cnt]=h[u];h[u]=cnt;
}
vector<int> q,tmp;
int f[305],dis[305];
void bfs(int st){
	for(int i=1;i<=n;i++){
		f[i]=0;
		dis[i]=inf;
	}
	q.push_back(st);
	f[st]=1;
	dis[st]=0;
	while(!q.empty()){
		tmp=q;
		q.clear();
		for(int i=0;i<(int)tmp.size();i++){
			int u=tmp[i];
			for(int j=h[u];j;j=nxt[j]){
				int v=to[j];
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					f[v]=f[u];
					q.push_back(v);
				}else if(dis[v]==dis[u]+1){
					f[v]+=f[u];
				}
			}
		}
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			h[i]=0; 
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(abs(x[i]-x[j])<=d){
						add(i,j);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(f[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
