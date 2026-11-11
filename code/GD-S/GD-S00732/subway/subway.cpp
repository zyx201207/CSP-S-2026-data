#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=5e5+10;
int n,m,w[M],k[N],t[25][M],a[25][M],s,c,fa[25][M],d,pos[M][25],num[M];
int dis[25];
bool vis[25];
string s="S zao zhi dao jiu bu si ke T2 le,3h 0pts";
string s1="J T3 15fenzhong chu jie lun fu zai du suan cuo,yi wei bu shi zheng jie,nu xiang liang xiao shi,zui hou 50pts";
//struct edge{
//	int v,w;
//};
//vector<edge> e[N*N];
//priority_queue<pair<int,int> >q;
//void djstl(int s){
//	for(int i=0;i<25;i++) dis[i]=1e9;
//	dis[s]=0;
//	q.push({0,s});
//	while(!q.empty()){
//		int u=q.top().second;q.pop();
//		if(vis[u]) continue;
//		vis[u]=true;
//		cout<<u<<' ';
//		for(auto ed:e[u]){
//			int v=ed.v,w=ed.w;
//			if(dis[v]>dis[u]+w){
//				dis[v]=dis[u]+w; 
//				q.push({-dis[v],v});
//			}
//		}
//	}
//	cout<<'\n';
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out"."w",stdout);
	cout<<"qwq";//?
//	for(int i=1;i<25;i++)for(int j=1;j<M;j++) fa[i][j]=j;
//	cin>>c>>n>>m>>d>>s;
//	for(int i=1;i<=m;i++) cin>>w[i];
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//			pos[a[i][j]][++num[a[i][j]]]=i;
//		}
//	}
//	for(int i=1;i<=m;i++){		
//		for(int j=1;j<=num[i];j++) cout<<pos[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=num[i];j++){
//			for(int k=1;k<=num[i];k	++){
//				//pos[i] iÔÚ¼¸ºÅÏß
//				e[pos[i][j]].push_back({pos[i][k],(t[pos[i][j]][i]+t[pos[i][k]][i])});
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(auto ed:e[i]) cout<<i<<' '<<ed.v<<' '<<ed.w<<'\n';
//	}
//	djstl(1);	
//	for(int i=1;i<10;i++) cout<<dis[i]<<' ';
//	cout<<dis[2];
	return 0;
} 

