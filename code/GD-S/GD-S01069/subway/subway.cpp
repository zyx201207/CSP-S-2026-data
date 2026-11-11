#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
#define int unsigned long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define DF(i,a,b) for(int i=(a);i>=(b);i--)
#define pt array<int,2>
const int N=505,M=2e4+10,V=1e7+4e4+505,QQ=1e5+10,inf=1e18;
int c,n,m,d,q,hd[V],cnt,str[QQ],id,dis[V],ans[QQ];
struct edge{int to,w,nx;}e[V];
inline void add(int u,int v,int w){
	e[++cnt]={v,w,hd[u]},hd[u]=cnt;
	e[++cnt]={u,w,hd[v]},hd[v]=cnt;
}
struct que{int u,v;}Q[QQ];
bool us[M],vis[V];
vector<pt>ask[QQ];
struct node{
	int to,w;
	friend bool operator<(node x,node y){return x.w>y.w;}
};
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	F(i,1,m){
		int w;cin>>w;
		add(i,i+m,w);
	}
	F(i,1,n){
		int l;cin>>l;
		F(j,1,l){
			int a,t;cin>>a>>t;
			add(a+m,a+(i+1)*m,t);
			add(a+(i+1)*m,(n+2)*m+i,0);
//			cout<<"Link! "<<(a+(i+1)*m)<<" "<<(n+2)*m+i<<"\n";
		}
	}
	F(i,1,q){
		int u,v;cin>>u>>v;
		Q[i]={u,v};us[u]=1;
		ask[u].push_back({v,i});
	}
	F(i,1,m)if(us[i])str[++id]=i;
	F(_,1,id){
		int s=str[_];
//		cout<<s<<"\n";
		F(i,1,(n+2)*m+n)dis[i]=inf,vis[i]=0;
		dis[s]=0;
		priority_queue<node>qu;
		qu.push({s,dis[s]});
		while(!qu.empty()){
			node x=qu.top();qu.pop();
			int u=x.to;
			if(vis[u])continue;
			vis[u]=1;
			for(int i=hd[u];i;i=e[i].nx){
				int v=e[i].to,w=e[i].w;
				if(dis[v]>dis[u]+w){
//					cout<<u<<" "<<v<<" "<<w<<"\n";
					dis[v]=dis[u]+w;
					if(!vis[v])qu.push({v,dis[v]});
				}
			}
		}
		for(pt tmp:ask[s]){
			int v=tmp[0],ii=tmp[1];
//			cout<<v<<" "<<ii<<" "<<dis[v]<<"\n";
			ans[ii]=dis[v];
		}
	}
	F(i,1,q)cout<<ans[i]<<"\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
