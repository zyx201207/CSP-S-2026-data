#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000005;
struct str{
	int d,t;
}u,v;
int c,t,n,k,x,y,ans=0x3f3f3f3f3f3f3f3f,a[1000005];
vector<int> g[maxn];
void bfs(){
	int it=0;
	queue<str>q;
	u.t=0;
	for(int i=1;i<=n;i++){
		u.d=a[i];
		q.push(u);
	}
	while(q.size()){
		u=q.front();
		q.pop();
		it=max(it,u.t);
		for(int i=0;i<g[u.d].size();i++){
			v.d=g[u.d][i];
			v.t=u.t+1;
			q.push(u);
		}
	}
	ans=min(ans,it);
}
void dfs(int x,int y){
	if(y==k){
		bfs();
		return;
	}
	dfs(x+1,y);
	a[y+1]=x;
	dfs(x+1,y+1);
}
signed mian(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		mian();
	}
	return 0;
} 
