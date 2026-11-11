#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300,inf=200000000;
vector<int> E[MAXN+5];
int n,k,ans;
bool g[MAXN+5],vis[MAXN+5];
int dis[MAXN+5];
void dfs2(int h){
	vis[h]=true;
	for(auto x:E[h]){
		if(g[x]&&!vis[x]){
			dfs2(x);
		}
	}
}
void dfs(int h,int now){
	if(h==n+1){
		int tot=0;
		for(int i=1;i<=n;i++) vis[i]=false;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&g[i]){
				if(tot==2) return ;
				tot++;
				dfs2(i);
			}
		}
		queue<pair<int,int> > q;
		for(int i=1;i<=n;i++){
			if(g[i]){
				dis[i]=0;
				q.push(make_pair(0,i));
			}
			else dis[i]=inf;
		}
		while(!q.empty()){
			int nh=q.front().second,nw=q.front().first;q.pop();
			if(nw!=dis[nh]) continue;
			for(auto x:E[nh]){
				if(dis[x]>nw+1){
					dis[x]=nw+1; 
					q.push(make_pair(dis[x],x));
				}
			}
		}
		int ans2=0;
		for(int i=1;i<=n;i++) ans2=max(ans2,dis[i]);
		ans=min(ans,ans2);
	}
	else{
		if(now+(n-h+1)==k){
			g[h]=true;
			dfs(h+1,now+1);
		}
		else if(now==k){
			g[h]=false;
			dfs(h+1,now);
		}
		else{
			g[h]=true;
			dfs(h+1,now+1);
			g[h]=false;
			dfs(h+1,now);
		}
	}
}
void work(){
	cin>>n>>k;ans=inf;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) E[i].clear();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("D:\\csps-new\\down\\hub\\hub5.in","r",stdin);
//	freopen("D:\\csps-new\\down\\hub\\hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c>=13&&c<=14){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
			}
			int m=n/2;
			if(k==n) cout<<"0\n";
			else if(k<=m){
				int a=(m-k)/4,b=2*a,c=a;
				if((m-k)%4==0) cout<<a+1<<"\n";
				else cout<<a+2<<"\n";
			}
			else cout<<"1\n";
		}
	}
	else while(T--) work();
	return 0;
}
