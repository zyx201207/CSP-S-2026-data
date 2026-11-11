#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
struct edge{
	int from,to,nxt,val;
}e[N*2];
int first[N*21],tot=0;
void add(int u,int v,int val){
	e[++tot].to=v;
	e[tot].from=u;
	e[tot].nxt=first[u];
	e[tot].val=val;
	first[u]=tot;
}
int son[N][21],cnt=0;
int dis[N*20];
struct node{
	int x,dis;
};
bool operator<(node a,node b){
	return a.dis>b.dis;
}
bool vis[N*20];
priority_queue<node> qu;
void dij(int s){
	for(int i=1;i<=cnt;i++){
		dis[i]=1000000000;
		vis[i]=0;
	}
	dis[s]=0;
	qu.push({s,0});
	while(!qu.empty()){
		node uu=qu.top();
		qu.pop();
		int u=uu.x;
		if(dis[u]!=uu.dis)continue;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=first[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				qu.push({v,dis[v]});
			}
		}
	}
}
struct que{
	int l,r,id;
}qq[100010];
bool cmp(que a,que b){
	return a.l<b.l;
}
int ans[100100];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		int lstk=-1;
		for(int j=1;j<=ki;j++){
			int ak,tk;
			cin>>ak>>tk;
			son[ak][i]=++cnt;
			add(ak,cnt,tk);
			add(cnt,ak,tk);
			if(lstk!=-1){
				add(lstk,cnt,0);
				add(cnt,lstk,0);
			}
			lstk=cnt;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qq[i].l>>qq[i].r;
		qq[i].id=i;
	}
	sort(qq+1,qq+1+q,cmp);
	int cur=-1;
	for(int i=1;i<=q;i++){
		if(qq[i].l!=cur){
			dij(qq[i].l);
			ans[qq[i].id]=dis[qq[i].r]+w[qq[i].l]+w[qq[i].r];
			cur=qq[i].l;
		}
		else{
			ans[qq[i].id]=dis[qq[i].r]+w[qq[i].l]+w[qq[i].r];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
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
