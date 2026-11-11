#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
#define fi first
#define se second
const int N=1000010;
struct Edge{
	int to,nxt,w;
}edge[N<<1];
int head[N],cnt=0;
void add(int u,int v,int w){
	edge[++cnt].to=v,edge[cnt].nxt=head[u],edge[cnt].w=w,head[u]=cnt;
}
struct ETE{
	int a,t,id;
};
struct Node{
	int num;
	vector<ETE>st;
}s[N];
int W[N];
vector<int>vec[N];
int ccc[N];
priority_queue<PII,vector<PII>,greater<PII> >q;
int dis[N],vis[N];
int dij(int st,int ed){
	memset(dis,0x3f,sizeof(dis)),memset(vis,0,sizeof(vis));
	q.push({dis[st]=0,st});
	while(!q.empty()){
		auto t=q.top().se;q.pop();
		if(vis[t])continue;
		vis[t]=1;
		for(int i=head[t];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[t]+edge[i].w){
				dis[v]=dis[t]+edge[i].w;
				q.push({dis[v],v});
			} 
		}
	}
	return dis[ed]; 
}
int ida[N],idx=0;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=m;i++)ida[i]=++idx;
	for(int i=1;i<=n;i++){
		cin>>s[i].num;
		for(int j=0,a,t;j<s[i].num;j++){
			cin>>a>>t;
			s[i].st.push_back({a,t,++idx});
			vec[a].push_back(i);
			add(idx,ida[a],t),add(ida[a],idx,t);
			if(j>0)add(idx,s[i].st[j-1].id,0),add(s[i].st[j-1].id,idx,0);
//			cout<<a<<"---"<<i<<"\n";
		}
	}
//	cout<<"vec:\n";
//	for(int i=1;i<=m;i++){
//		cout<<"["<<i<<"]: ";
//		for(auto j:vec[i])cout<<j<<" ";
//		cout<<"\n";
//	} 
//	cout<<"\n";
	while(q--){
		int st,ed;cin>>st>>ed;
		cout<<W[st]+W[ed]+dij(ida[st],ida[ed])<<"\n";
	}
	return 0;
	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
