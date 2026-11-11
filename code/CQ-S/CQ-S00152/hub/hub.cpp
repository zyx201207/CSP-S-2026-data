#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> b[N];
int X,n,k,fa[N];
bool vis[N],tg[N];
int Find(int x){return fa[x]==x?x: fa[x]=Find(fa[x]);}
int dfs(int x,int I,int D){
	if(tg[x]&&Find(x)!=I) return D;
	if(vis[x]) return 0;
//	cout<<"%%"<<x<<" "<<vis[x]<<"\n";
	vis[x]=1;
	for(int y: b[x]){
		int re=dfs(y,I,D+1);
		if(re) return re;
	}return 0;
}
bool check(){
	struct info{
		int id,ds;
	};
	queue<info> q;
	for(int i=1;i<=n;i++) vis[i]=0,tg[i]=0;
	for(int i=1;i<=n;i++)
		if(b[i].size()==1u)
			q.push({i,0});
	for(;!q.empty();){
		int ds=q.front().ds,x=q.front().id;q.pop();
		if(vis[x]) continue;
//		cout<<"##"<<x<<" "<<ds<<" "<<vis[x]<<"\n";
		vis[x]=1;
//		cout<<"%%"<<vis[x]<<"\n";
		if(ds>X) tg[x]=1;
		for(int y: b[x]) if(!vis[y]) q.push({y,ds+1});
	}//cout<<"@@@@@\n";
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans=0;
	for(int i=1;i<=n;i++) if(tg[i]){
		for(int y: b[i]) if(tg[y]) fa[Find(i)]=Find(y);
		ans++;
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) if(tg[i]&&fa[i]==i) ans+=dfs(i,i,0);
	return ans<=k;
}
void work(){
	cin>>n>>k;
	for(int x,y,i=n-1;i--;) cin>>x>>y,
		b[x].push_back(y),b[y].push_back(x);
	int L=0,R=n;
	for(;L<R;){
		X=(L+R)>>1;
		if(check()) R=X;
		else L=X+1;
	}cout<<L<<"\n";
	for(int i=1;i<=n;i++) b[i]={};
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;for(cin>>c>>T;T--;) work();
}
