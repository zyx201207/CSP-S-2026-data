#include <bits/stdc++.h>
// #define int long long
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=5e5+10, M=2e6+10;
int c,n,m,d,q;
int w[N],cst[505][N];
vector<int> qv[1009];
struct edge{int to,nxt,w;} e[M];
int tot,hd[M];
void add2(int u,int v,int w){
	e[++tot]={v,hd[u],w};
	hd[u]=tot;
}
void add(int u,int v,int w){
	add2(u,v,w); add2(v,u,w);
	// cout<<u<<"--"<<v<<" "<<w<<endl;
}
const int D=1e6+10;
int dis[D],vis[D];
typedef pair<int,int> pii;
void dij(int s){
	for(int i=0;i<=(n+1)*m;i++){
		dis[i]=1e9; vis[i]=0;
	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second; q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
struct ques{int id,s,t,ans;} qq[100009];


signed main(){ // 44pts
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	// 0--s  1.2.3---abc
	// 1--n
	for(int i=1;i<=n;i++){
		int k=read(),lst=-1;
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			cst[i][a]=t;
			qv[a].push_back(i);
			// 0--> i*m+a
			add(a,i*m+a,w[a]+t);
			if(lst!=-1)
				add(i*m+a,i*m+lst,0);
			lst=a;
		}
	}
	// cout<<"------"<<endl;
	// for(int i=1;i<=m;i++){
	// 	// cout<<qv[i].size()<<" ";
	// 	cout<<i<<"->  ";
	// 	for(int j=0;j<qv[i].size();j++)
	// 		cout<<qv[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	for(int i=1;i<=m;i++){
		for(int j=0;j<qv[i].size();j++){
			for(int k=j+1;k<qv[i].size();k++){
				int x=qv[i][j],y=qv[i][k];
				add(x*m+i,y*m+i,cst[x][i]+cst[y][i]);
			}
		}
	}

	// while(q--){
	// 	int s=read(),t=read();
	// 	dij(s);
	// 	cout<<dis[t]<<endl;
	// }

	for(int i=1;i<=q;i++){
		int s=read(),t=read();
		qq[i]={i,s,t};
	}
	sort(qq+1,qq+q+1,[](ques q1,ques q2){return q1.s<q2.s;});
	int ls=-1;
	for(int i=1;i<=q;i++){
		if(ls==qq[i].s)
			qq[i].ans=dis[qq[i].t];
		else{
			dij(qq[i].s);
			qq[i].ans=dis[qq[i].t];
			ls=qq[i].s;
		}
	}
	sort(qq+1,qq+q+1,[](ques q1,ques q2){return q1.id<q2.id;});
	for(int i=1;i<=q;i++){
		cout<<qq[i].ans<<endl;
	}




	return 0;
}