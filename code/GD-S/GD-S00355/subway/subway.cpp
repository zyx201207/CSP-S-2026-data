#include<bits/stdc++.h>
bool st;
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int w[M],k[N],len,h[M];
vector<int>a[N],t[N];
ll f[N][N];
struct edge{int v,next;}e[N];
inline void add(int u,int v){
	e[++len]={v,h[u]};
	h[u]=len;
}
bool ed;
int main(){
	int c,n,m,d,q,x,y;
//	printf("%.10lf",abs(&st-&ed)*1.0/1024/1024);
//	freopen("subway3.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
//			t[i][j]+=t[i][j-1];
		}
		add(a[i][1],i);
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
			if(i^j)
				f[i][j]=1e18;
	priority_queue<pair<int,int>>p;
	for(int i=1,u,te,j,l;i<=m;++i){
		p.push({0,i});
//		if(f[i][i])exit(1);
		while(!p.empty()){
			te=p.top().first;
			u=p.top().second;
			p.pop();
			if(f[i][u]<te)continue;
			for(j=h[u];j;j=e[j].next){
				te=e[j].v;
				for(l=1;l<=k[te];++l)
					if(f[i][a[te][l]]>f[i][u]+t[te][1]+t[te][l]){
						f[i][a[te][l]]=f[i][u]+t[te][1]+t[te][l];
						p.push({-f[i][a[te][l]],a[te][l]});
					}
			}
		}
		for(j=i+1;j<=n;++j)
			if(f[j][i]>f[i][j])
				f[j][i]=f[i][j];
	}
//	for(int i=1;i<=m;++i,cerr<<'\n')
//		for(int j=1;j<=m;++j)
//			cerr<<f[i][j]<<' ';
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<'\n';
	}
	return 0;
}
/*
priority_queue
*/
