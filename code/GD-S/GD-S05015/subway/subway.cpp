#include<bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
//map<pair<int,int> > mmp;
const int N=502,M=500005;
int n,m,c,d,q;
int w[M];
int k[N];
vector<pii> V1[N];//<a,t>
int x,y;
struct edge{
	long long to,w;
};
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<edge> Mp[M];//x-w->y
priority_queue<pii,vector<pii>,greater<pii> > Qu;//<dis,x>
int dis[M];
bool vis[M];
int aa;
void dj(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	Qu.push(make_pair(0,s));
	long long p,W;
	while(!Qu.empty()){
		p=Qu.top().second;
		W=Qu.top().first;
		Qu.pop();
		if(vis[p])continue;
		vis[p]=true;
		
		for(auto i:Mp[p]){
			aa=i.to;
			if(dis[aa]>dis[p]+i.w)dis[aa]=dis[p]+i.w;
			Qu.push(make_pair(dis[aa],aa));
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a,t;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a=read();
			t=read();
			V1[i].push_back(make_pair(a,t));
		}
	}
	int b;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int kk=j+1;kk<k[i];kk++){
				a=V1[i][j].first;
				b=V1[i][kk].first;
				t=V1[i][j].second+V1[i][kk].second;
				Mp[a].push_back(edge{b,t});
				Mp[b].push_back(edge{a,t}); 
			}
		}
	}
	while(q--){
		x=read(),y=read();
//		if(mmp[make_pair(x,y)]!=0)cout<<mmp[make_pair(x,y)]<<'\n';
//		else{
			dj(x);
//			mmp[make_pair(x,y)]=dis[y]+w[x]+w[y];
//			mmp[make_pair(y,x)]=dis[y]+w[x]+w[y];
			cout<<dis[y]+w[x]+w[y]<<'\n';
//		}
	}
	return 0;
}

