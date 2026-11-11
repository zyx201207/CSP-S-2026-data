#include<bits/stdc++.h>
using namespace std;
using ci=const int;using ui=unsigned int;using cui=const unsigned int;using ll=long long;
using cll=const long long;using ull=unsigned long long;using cull=const unsigned long long;
template<class T>inline T& Min(T &x,const T y){
	return x<y?x:x=y;
}
template<class T>inline T& Max(T &x,const T y){
	return x<y?x=y:x;
}
cui oo=1u<<30;cull inf=1ull<<62;
cui N=505,M=5e5+5;
ui _,n,m,w[M],q,k,x,y;
ull dis[N][N],ans;
struct Node{
	Node()=default;
	Node(cui &id,cui &tim):id(id),tim(tim){}
	ui id,tim;
}a;
bool operator<(const Node a,const Node b){
	return a.tim>b.tim;
}
vector<Node>v[M];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_>>n>>m>>_>>q;
	fill(*dis,*dis+N*N,inf);
	for(ui i=1;i<=m;i++)cin>>w[i];
	for(ui i=1;i<=n;i++){
		cin>>k,dis[i][i]=0;
		for(ui j=1;j<=k;j++){
			cin>>a.id>>a.tim;
			v[a.id].emplace_back(i,a.tim);
		}
	}
	for(ui i=1;i<=m;i++){
		for(const Node &a:v[i]){
			for(const Node &b:v[i]){
				Min<ull>(dis[a.id][b.id],a.tim+b.tim);
			}
		}
//		sort(v[i].begin(),v[i].end(),[](const Node a,const Node b){return a.id<b.id;});
//		_=v[i].size();
//		for(ui j=0;j<_;j++)
//			for(ui k=0;k<_;k++){
//				const Node &a=v[i][j],&b=v[i][k];
//				Min<ull>(dis[a.id][b.id],a.tim+b.tim);
//			}
	}
	for(ui k=1;k<=n;k++){
		for(ui i=1;i<=n;i++){
			for(ui j=1;j<=n;j++){
				Min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ui i=1;i<=q;i++){
		cin>>x>>y,ans=inf;
		for(const Node &a:v[x]){
			for(const Node &b:v[y]){
				Min(ans,a.tim+b.tim+dis[a.id][b.id]);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
