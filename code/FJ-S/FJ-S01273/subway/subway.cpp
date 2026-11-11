#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
const int K=5e7+10;
int c,n,m,dd,q;
int w[N],k[505];
int ver[K],nex[K],edge[K],head[K];
int tot;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
int d[N],vi[N];
struct node{
	int xx,yy;
};
void dijs(int u,int v){
	queue<int >qu;
	qu.push(u);
	d[u]=0;
	vi[u]=1;
	while(qu.size()){
		int x=qu.front();
		qu.pop();
		vi[x]=0;
		for(int i=head[x];i;i=nex[i]){
			int y=ver[i],z=edge[i];
			if(d[x]+z<d[y]){
				d[y]=d[x]+z;
				if(!vi[i]){
					vi[i]=1;
					qu.push(y);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,t;
			cin>>x>>t;
			add(m+i,x,t);
			add(x,m+i,t); 
		}
	}
	for(int i=1;i<=q;++i){
		memset(d,0x3f,sizeof(d));
		memset(vi,0,sizeof(vi));
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		dijs(x,y);
		cout<<ans+d[y]<<endl;
	}
	return 0;
}
