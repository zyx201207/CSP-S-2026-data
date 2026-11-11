#include<bits/stdc++.h>
using namespace std;
const int N=501;
const int M=3000010;
vector<pair<int,int> >v[M];
int c,n,m,d,q,dis[M],w[M],k[N],fa[M];
int get(int x){
	if(x!=fa[x]) return x=get(fa[x]);
	return x;
}
struct sub{
	int a,t;
};
vector<sub>s[N];//存每一条线路 
map<pair<int,int>,int>mp;//存每个点所在线路映射的点 
struct edge{
	int x,y,z;
}e[M];//存mst需要的edge 
bool cmp(edge aa,edge bb){
	return aa.z<bb.z;
}
vector<pair<int,int> >poi[M];//first为点所在的线路，second为所在线路的花费
int dr[M],f[M][22],dep[M];
void dfs(int now,int fa){
	if(now>M) cout<<"!";
	f[now][1]=fa;
	dep[now]=dep[fa]+1;
	for(int i=0;i<v[now].size();i++){
		int y=v[now][i].first,z=v[now][i].second;
		if(y==fa) dr[now]=dr[fa]+z;
	}
	for(int i=0;i<v[now].size();i++){
		int y=v[now][i].first,z=v[now][i].second;
		if(y==fa) continue;
		dfs(y,now);
	}
} 
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	if(dep[x]!=dep[y]){
		int cha=dep[y]-dep[x];
		for(int i=20;i>=0;i--){
			if((cha>>i)&1) y=f[y][i+1];
		}
	}
	if(x==y) return x;
	while(x!=y){
		for(int i=20;i>=2;i--){
			if(f[x][i]==f[y][i]) continue;
			x=f[x][i],y=f[y][i];
			break;
		}
		if(x!=y) return f[x][1];
	}
	return x;
}
int tot=0,sume;
void input_prework(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			sub tmp;
			cin>>tmp.a>>tmp.t;
			s[i].push_back(tmp);
			mp[{tmp.a,i}]=++tot;
			poi[tmp.a].push_back({i,tmp.t});
		} 
	}
	for(int i=1;i<=m;i++) mp[{i,n+1}]=++tot; 
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<poi[i].size();j++){
//			cout<<i<<" "<<poi[i][j].first<<" "<<mp[{i,poi[i][j].first}]<<endl; 
//		}
//		cout<<i<<" "<<n+1<<" "<<mp[{i,n+1}]<<endl;
//	}
}
void build_graph(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			e[++sume].x=mp[{s[i][j-1].a,i}];
			e[sume].y=mp[{s[i][j].a,i}];
			e[sume].z=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(poi[i].size()>1){
			int tmpm=poi[i].size();
			for(int i1=0;i1<tmpm;i1++){
				for(int i2=0;i2<tmpm;i2++){
					if(i1==i2) continue;
					e[++sume].x=mp[{i,poi[i][i1].first}];
					e[sume].y=mp[{i,poi[i][i2].first}];
					e[sume].z=poi[i][i1].second+poi[i][i2].second;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<poi[i].size();j++){
			e[++sume].x=mp[{i,poi[i][j].first}];
			e[sume].y=mp[{i,n+1}];
			e[sume].z=poi[i][j].second;
		}
	}
//	for(int i=1;i<=sume;i++) cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].z<<endl;
}
void calc_mst(){
	sort(e+1,e+sume+1,cmp);
	for(int i=1;i<=tot;i++) fa[i]=i;
	for(int i=1;i<=sume;i++){
		int xx=e[i].x,yy=e[i].y,zz=e[i].z;
		int p1=get(xx);
		int p2=get(yy);
		if(p1!=p2){
			fa[p1]=p2;
			v[xx].push_back({yy,zz});
			v[yy].push_back({xx,zz});
		}
	}//cout<<tot<<endl;
//	for(int i=1;i<=tot;i++){
//		for(auto j:v[i]) cout<<j.first<<" ";cout<<endl; 
//	}
}
void preworklca(){
	dfs(1,0);
	for(int i=2;i<=20;i++){
		for(int j=1;j<=tot;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
//	for(int i=1;i<=tot;i++) cout<<dr[i]<<" ";cout<<endl;
//	for(int i=1;i<=tot;i++) cout<<dep[i]<<" ";cout<<endl;
//	for(int i=1;i<=tot;i++) cout<<f[i][1]<<" ";cout<<endl;
} 
void query(){
	while(q--){
		int x,y;
		cin>>x>>y;
		int tmpx=x,tmpy=y;
		x=mp[{x,n+1}],y=mp[{y,n+1}];
		cout<<dr[x]+dr[y]-dr[lca(x,y)]+w[tmpx]+w[tmpy]<<endl;
		cout<<dr[x]<<" "<<dr[y]<<" "<<dr[lca(x,y)]<<" "<<w[tmpx]<<" "<<w[tmpy]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input_prework();
	build_graph();
	calc_mst();
	preworklca();
	query();
}

