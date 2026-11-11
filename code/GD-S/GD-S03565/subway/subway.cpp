#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=5e3+5;
int c;
int n,m,d,q,w[N];
int x[N],y[N];
int ans[M][M];
bool k[N];
struct st{
	int v,t;
};
vector<st> v[N];
void dfs(int a,int b,int t){
	for(int i=0;i<v[b].size();i++){
		if(ans[a][v[b][i].v]>t+v[b][i].t){
			ans[a][v[b][i].v]=t+v[b][i].t;
			ans[v[b][i].v][a]=min(ans[v[b][i].v][a],ans[a][v[b][i].v]);
			ans[a][v[b][i].v]=ans[v[b][i].v][a];
			dfs(a,v[b][i].v,t+v[b][i].t);
		}
	}
}
queue<st> que;
int bfs(int a,int b,int t){
	for(int i=0;i<v[b].size();i++){
		if(v[b][i].v==a){
			return t+v[b][i].t;
		}
		if(k[v[b][i].v]==0){
			k[v[b][i].v]=1;
			que.push({v[b][i].v,t+v[b][i].t});
		}
	}
	if(!que.empty()){
		int fv=que.front().v,ft=que.front().t;
		que.pop();
		return bfs(a,fv,ft);
	}
	return 0;
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>x[j]>>y[j];
			for(int ij=1;ij<j;ij++){
				v[x[ij]].push_back({x[j],y[ij]+y[j]});
				v[x[j]].push_back({x[ij],y[ij]+y[j]});
			} 
		}
	}
	if(m<=M){
		memset(ans,0x3f3f3f,sizeof(ans));
		for(int i=1;i<=m;i++){
			ans[i][i]=0;
			dfs(i,i,0);
		}
		for(int i=1;i<=q;i++){
			int xx,yy;
			cin>>xx>>yy;
			cout<<ans[xx][yy]+w[xx]+w[yy]<<"\n";
		}
		return;
	}
	if(12<=c&&c<=19){
		for(int i=1;i<=q;i++){
			int xx,yy;
			cin>>xx>>yy;
			cout<<bfs(xx,yy,0)+w[xx]+w[yy]<<"\n";
			memset(k,0,sizeof(k));
		}
		return;
	}
	for(int i=1;i<=q;i++){
		int xx,yy;
		cin>>xx>>yy;
		cout<<bfs(xx,yy,0)+w[xx]+w[yy]<<"\n";
		memset(k,0,sizeof(k));
	}
}
signed main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
