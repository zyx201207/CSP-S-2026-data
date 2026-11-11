#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,asya;
int w[N],k[505],x,y;
struct _{
	int id,di;
};
vector<int > a[505];
vector<int > t[505];
vector<_ > g[N];
//vector<_ > bi[505];
int dit[505][505];
//bool vis[505][505];
//queue<_ > qu;
//_ ku[100000000];
//int ta,ha;
//void bfs(int sta){
//	memset(vis,0,sizeof vis);
////	for(int i=1;i<=n;i++){
////		for(int j=1;j<=n;j++){
////			vis[i][j]=0;
////		}
////	}
//	qu.push({sta,0});
////	ta=1;ha=1;
////	ku[ta]={sta,0};
//	while(!qu.empty()/*ha<=ta*/){
//		_ tmp=qu.front();qu.pop();
////		_ tmp=ku[ha];ha++;
//		vis[sta][tmp.id]=1;
//		dit[sta][tmp.id]=min(dit[sta][tmp.id],tmp.di);
//		dit[tmp.id][sta]=min(dit[tmp.id][sta],tmp.di);
////		cout<<sta<<" "<<tmp.id<<"\n";
//		for(int i=1;i<=n;i++){
//			int tpp=tmp.di+dit[tmp.id][i];
//			if(tpp<dit[sta][i]||(!vis[sta][i]&&tpp==dit[sta][i])){
//				qu.push({i,tmp.di+dit[tmp.id][i]});
////				ku[++ta]={i,tpp};
//			}
//		}
////		for(_ caa:bi[tmp.id]){
////			int i=caa.id;
////			if(tmp.di+caa.di<dit[sta][i]||(!vis[sta][i]&&tmp.di+caa.di==dit[sta][i])){
////				qu.push({i,tmp.di+caa.di});
////				vis[sta][tmp.id]=1;
////			}
////		}
//	}
//	
//}
//i love the world and everything in it.
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
			g[u].push_back({i,v});
		}
	}
	memset(dit,0x3f,sizeof dit);
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(_ ca:g[a[i][j]]){
				if(ca.id==i)continue;
//				vis[i][ca.id]=vis[ca.id][i]=1;
				dit[i][ca.id]=min(t[i][j]+ca.di,dit[i][ca.id]);
				dit[ca.id][i]=min(t[i][j]+ca.di,dit[ca.id][i]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(vis[i][j]){
//				bi[i].push_back({j,dit[i][j]});
//				bi[j].push_back({i,dit[i][j]});
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		dit[i][i]=0;
//		bfs(i);
	}
	for(int i=1;i<=n;i++){
//		dit[i][i]=0;
//		bfs(i);
		for(int j=1;j<=n;j++){
			for(int h=1;h<=n;h++){
				dit[i][j]=min(dit[i][j],dit[i][h]+dit[h][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dit[i][j]<<"\t";
//		}
//		cout<<"\n";
//	}
	while(q--){
		cin>>x>>y;
		asya=0x3f3f3f3f3f3f3f3f;
		for(_ il:g[x]){
			for(_ jl:g[y]){
//				cout<<il.id<<" "<<jl.id<<" "<<w[x]+w[y]+il.di+jl.di+dit[il.id][jl.id]<<"\n";
				asya=min(asya,w[x]+w[y]+il.di+jl.di+dit[il.id][jl.id]);
				
				
			}
		}
		cout<<asya<<"\n";
		
	}
	return 0;
} 
