#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+(ch-'0');
	return x*f;
}
const int N=5e5+10;
int c,n,m,d,q,a[N],dis[N],vis[N];
vector<pii>g[N];
void dij(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push({x,0});
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().first;
		q.pop();
		if(vis[u]) continue;
		else vis[u]=1;
		for(auto x:g[u]){
			int v=x.first,t=x.second;
			if(dis[v]>dis[u]+t){
				dis[v]=dis[u]+t;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	clock_t start=clock();
	c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int num=n+1;
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		int u,t1;cin>>u>>t1;
		g[u].emplace_back(num,t1);
		g[num].emplace_back(u,t1);
		num++;
		for(int j=2;j<=k;j++){
			int v,t2;cin>>v>>t2;
			g[v].emplace_back(num,t2);
			g[num].emplace_back(v,t2);
			g[num-1].emplace_back(num,0);
			g[num].emplace_back(num-1,0);
			num++;
		}
	}
//	for(int i=1;i<=num;i++){
//		cout<<i<<"   ";
//		for(auto x:g[i]){
//			cout<<x.first<<" "<<x.second<<"  ";
//		}
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
		cout<<a[x]+a[y]+dis[y]<<'\n';
//		for(int i=1;i<=num;i++){
//			cout<<dis[i]<<" ";
//		}
//		cout<<'\n';
	}
//	cout<<'\n'<<clock()-start<<"ms";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
