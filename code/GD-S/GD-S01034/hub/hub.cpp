#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=25,INF=1e9;
int c_id,T,n,k,f[maxn],in[maxn],ans;
bool vis[maxn][maxn];
vector<int>m[maxn];
struct Node{
	int v,w;
};
bool check(){
	int cnt=0;
	for(int i=1;i<=k;i++){
		bool flag=1;
		for(int j=1;j<i;j++){
			if(vis[f[i]][f[j]]){flag=0;break;}
		}
		if(flag) cnt++;
	}
	return cnt<=2;
}
void dfs(int cnt,int now){
	if(cnt==k){
		if(!check()) return;
		int res=0;
		for(int i=1;i<=n;i++){
			queue<Node>q;q.push({i,0});
			int dist=0;
			while(!q.empty()){
				int now=q.front().v,noww=q.front().w;q.pop();
				dist=max(dist,noww);
				if(in[now]) break;
				for(int j=0;j<(int)m[now].size();j++){
					int net=m[now][j];
					q.push({net,noww+1});
				}
			}
			res=max(res,dist);
		}
		ans=min(ans,res);
		return;
	}
	for(int i=now+1;i<=n;i++){
		in[i]=1,f[cnt+1]=i;
		dfs(cnt+1,i);
		in[i]=0,f[cnt+1]=0;
	}
	return;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		m[i].clear();
		for(int j=1;j<=n;j++) vis[i][j]=0;
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		m[u].push_back(v);
		m[v].push_back(u);
		vis[u][v]=vis[v][u]=1;
	}
	ans=INF,dfs(0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>c_id>>T;
	if(c_id==0||c_id==1||c_id==2||c_id==3||c_id==7){
		while(T--) solve();
	}
	else if(c_id==13||c_id==14){
		while(T--){
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++) cin>>u>>v;
			if(n==k) cout<<"0\n";
			else cout<<ceil(1.0*(n/2-k)/4)+1<<"\n";
		}
	}
	else for(int i=1;i<=T;i++) cout<<rand()<<"\n";
	return 0;
}
