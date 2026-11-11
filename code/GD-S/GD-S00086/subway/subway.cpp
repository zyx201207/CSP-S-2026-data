#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10,O=1e6+10;
const int N=5e2+10;
int w[M];
int head[O],to[O],ne[O],id,v[O],dis[O];
void add(int x,int y,int z){
	to[++id]=y;
	v[id]=z;
	ne[id]=head[x];
	head[x]=id;
}
struct node{
	int u,v;
	bool operator <(const node &tmp)const{
		return v>tmp.v;
	}
};
priority_queue<node>qq;
void dij(int xx){
	for(int ii=0;ii<=1005;ii++){
		dis[ii]=2147483647ll;
	}
	qq.push({xx,0});
	dis[xx]=0;
	while(!qq.empty()){
		node tt=qq.top();
		qq.pop();
		for(int i=head[tt.u];i;i=ne[i]){
			if(dis[to[i]]>tt.v+v[i]){
				dis[to[i]]=tt.v+v[i];
				qq.push({to[i],dis[to[i]]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			add(i+500,a,t);
			add(a,i+500,t);
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=w[x]+w[y];
		dij(x);
		ans+=dis[y];
		printf("%lld\n",ans);
	}
} 
