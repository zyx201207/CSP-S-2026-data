#include<bits/stdc++.h>
using namespace std;
char ch[1<<20],*P,*Q;
#define gc() (((P==Q&&(P=(Q=ch)+fread(ch,1,1<<20,stdin))),P==Q)?EOF:*Q++)
#define int long long
inline int read(){
	int res=0;bool sign=false;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') sign=true;
	for(;isdigit(c);c=gc()) res=res*10+c-'0';
	return sign?-res:res;
}
int c,n,m,d,q,t[500005],dis[505][505];
vector<pair<int,int> >link[500005],point[505];
void add(int u,int v,int w){
	point[u].push_back({v,w}),point[v].push_back({u,w});
}
const int inf=1e17;
void dij(int st){
	for(int i=1;i<=n;i++) if(i!=st) dis[st][i]=inf;
	priority_queue<pair<int,int> >pq;
	pq.push({0,st});
	while(!pq.empty()){
		int x=pq.top().second,num=pq.top().first;pq.pop();
		if(num>dis[st][x]) continue;
		for(pair<int,int>i:point[x]) if(dis[st][i.first]>dis[st][x]+i.second)
			dis[st][i.first]=dis[st][x]+i.second,pq.push({-dis[st][i.first],i.first});
	}
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) t[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int to=read(),v=read();
			link[to].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++) for(int j=0;j<link[i].size();j++) for(int k=j+1;k<link[i].size();k++) 
		add(link[i][j].first,link[i][k].first,link[i][j].second+link[i][k].second);
	for(int i=1;i<=n;i++) dij(i);
	while(q--){
		int u=read(),v=read(),ans=inf;
		for(pair<int,int>i:link[u]) for(pair<int,int>j:link[v]) ans=min(ans,i.second+j.second+dis[i.first][j.first]);
		cout<<ans+t[u]+t[v]<<"\n";
	}
	return 0; 
}
