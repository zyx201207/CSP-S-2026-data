#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=405,M=505,N2=5e5+5;
int c,f[N][N],n,m,d,q,w[N2];
struct node{
	int k,a[N],t[N];
}l[M];
struct node2{
	int u,t;
};
void solve1(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i].k;j++){
			for(int k=1;k<=l[i].k;k++){
				f[l[i].a[j]][l[i].a[k]]=f[l[i].a[k]][l[i].a[j]]=min(f[l[i].a[j]][l[i].a[k]],l[i].t[j]+l[i].t[k]);
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=m;i++){
			for(int k=1;k<=m;k++){
				f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<f[u][v]+w[u]+w[v]<<"\n";
	}
}
vector<int>e[N2];
int bfs(int u,int v){
	bool vis[N2]={},vis2[M]={};
	queue<node2>qu;
	qu.push({u,0});
	vis[u]=1;
	while(qu.size()){
		node2 x=qu.front();
		qu.pop();
		for(int i=0;i<e[x.u].size();i++){
			if(vis2[e[x.u][i]])continue;
			for(int j=1;j<=l[e[x.u][i]].k;j++){
				if(l[e[x.u][i]].a[j]==v)return x.t+2;
				if(!vis[l[e[x.u][i]].a[j]]){
					vis[l[e[x.u][i]].a[j]]=1;
					qu.push({l[e[x.u][i]].a[j],x.t+2});
				}
			}
			vis2[e[x.u][i]]=1;
		}
	}
	return 114514;
}
void solve2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i].k;j++){
			e[l[i].a[j]].push_back(i);
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<bfs(u,v)*l[1].t[1]+w[u]+w[v]<<"\n";
	}
}
vector<node2>e1[N2];
int u1,v1,u11;
void solve3_(){
	int num=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l[i].k;j++){
			e1[l[i].a[j]].push_back({i,l[i].t[j]});
		}
	}
	for(int i=1;i<=m;i++){
		if(e1[i].size()==2){
			num=min(num,e1[i][0].t+e1[i][1].t);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u1>>v1;
		if(e1[u1].size()==2&&e1[v1].size()==2){cout<<w[u1]+w[v1]+min(e1[u1][0].t+e1[v1][0].t,e1[u1][1].t+e1[v1][1].t);}
		else{
			if(e1[u1].size()==2){
				cout<<w[u1]+w[v1]+e1[v1][0].t+min((e1[u1][0].u==e1[v1][0].u?0:num)+e1[u1][0].t,(e1[u1][1].u==e1[v1][0].u?0:num)+e1[u1][1].t)<<"\n";
			}
			else if(e1[v1].size()==2){
				cout<<w[u1]+w[v1]+e1[u1][0].t+min((e1[v1][0].u==e1[u1][0].u?0:num)+e1[v1][0].t,(e1[v1][1].u==e1[u1][0].u?0:num)+e1[v1][1].t)<<"\n";
			}
			else if(e1[u1][0].u==e1[v1][0].u){
				cout<<w[u1]+w[v1]+e1[u1][0].t+e1[v1][0].t<<"\n";
			}
			else{
				cout<<w[u1]+w[v1]+e1[u1][0].t+e1[v1][0].t+num<<"\n";
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i].k;
		for(int j=1;j<=l[i].k;j++)cin>>l[i].a[j]>>l[i].t[j];
	}
	if(c<=8)solve1();
	else if(c>=12&&c<=15)solve2();
	else if(c==20||c==21)solve3_();
	return 0;
}
//56 pts
