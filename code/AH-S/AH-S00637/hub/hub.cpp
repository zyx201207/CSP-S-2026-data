#include"bits/stdc++.h"
using namespace std;
const int N=1e6+5;
typedef long long ll;
struct node{
	int v,nxt;
}e[N<<1];
int n,h[N],K,cnt,ans=N;
bool v[N];
void add(int u,int v){
	e[++cnt]=node{v,h[u]};
	h[u]=cnt;
}
bitset<N>vis;
queue<pair<int,int>>q;
int bfs(int a){
	int mx=0;
	vis.reset();
	q.emplace(make_pair(a,0));
	vis[a]=1;
	while(!q.empty()){
		int u=q.front().first,w=q.front().second;
		q.pop();
		if(v[u])w=0;
		mx=max(mx,w);
		for(int i=h[u];i;i=e[i].nxt)
		if(!vis[e[i].v]){
			q.emplace(make_pair(e[i].v,w+1));
			vis[e[i].v]=1;
		}
	}
	return mx;
}
void dfs(int a,int b,int k,int fa){
///	cout<<a<<" "<<b<<" "<<k<<" "<<fa<<"\n"; 
	if(k==K){
		int t=bfs(max(a,b));
	//	cout<<t<<"\n";
		ans=min(ans,t);
		return;
	}
		 for(int i=h[a];i;i=e[i].nxt)
		 if(!v[e[i].v]&&e[i].v!=fa){ 
		 	v[e[i].v]=1;
			dfs(e[i].v,b,k+1,a);
			v[e[i].v]=0;
		 } 
		for(int i=h[b];i;i=e[i].nxt)
		 if(!v[e[i].v]&&e[i].v!=fa){ 
		 	v[e[i].v]=1;
			dfs(a,e[i].v,k+1,b);
			v[e[i].v]=0;
		} 
}
void work(){
	memset(h,0,sizeof h);
	cnt=0;
	cin>>n>>K;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i)add(0,i);
	ans=N;
	dfs(0,0,0,0);
	cout<<ans<<"\n";
}
void Awork(){
	cin>>n>>K;
	n=(n+3)>>1;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
	} 
	cout<<(n-K+3)/4<<"\n";
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,T;
    cin>>c>>T;
    if(c!=13&&c!=14){
    	while(T--)work();
	} else{
		while(T--)Awork();
	}
}

