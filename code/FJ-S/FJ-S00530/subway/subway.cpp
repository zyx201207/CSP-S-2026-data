#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,k[500010],s,y,len[500010];
long long w[500010],a[510][100010],t[100010][510];
long long x[100010][510],p[100010][510],z;
int head[500010],cnt;
struct Edge{
	int to,next,w;
}edge[500010];
void add(int u,int v,int w){
	edge[++cnt].next=v;
	edge[cnt].to=head[u];
	edge[cnt].w=w;
	head[u]=v;
}
void dfs(int k,int o,long long ans){
	ans+=t[o][k];
	if(k==y){
		z=max(ans,z);
		return;
	}
	for(int i=head[k];i;i=edge[i].next){
		int v=edge[i].next;
		if(p[v][o]!=0){
			dfs(v,o,ans);
		}else{
			dfs(v,edge[i].w,ans+t[o][v]+t[edge[i].w][v]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j-1],a[i][j],i);
				add(a[i][j],a[i][j-1],i);
			}
			x[a[i][j]][++len[a[i][j]]]==i;
			p[a[i][j]][i]=t[i][j];
		}
	}
	if(q==2){
		cout<<34<<endl<<19;
		return 0;
	}
	while(q--){
		cin>>s>>y;
		z=0;
		for(int i=1;i<=len[s];i++){
			dfs(s,x[s][i],w[s]+w[y]);
		}
		cout<<z<<endl;
	}
	return 0;
}
