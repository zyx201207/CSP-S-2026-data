#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
struct sub{
	int a[50000],t[50000];
}x[500];
int c,n,m,d,q,w[50000],vis[500000];
vector<node> e[500000];
long long minn=1000000;
void dfs(int u,int v,long long sum){
	vis[u]=1;
	if(sum>minn)return;
	if(u==v){
		if(minn=1000000||sum<minn)minn=sum;
	}else{
		for(auto t:e[u]){
			if(vis[t.v]==0&&((t.v>1000&&u<1000)||(t.v<1000&&u>1000))){
				vis[t.v]=1;
				dfs(t.v,v,sum+t.w);
				vis[t.v]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[i].a[j]>>x[i].t[j];
			if(j>1)e[i*1000+x[i].a[j-1]].push_back({i*1000+x[i].a[j],0});
			e[i*1000+x[i].a[j]].push_back({0,x[i].t[j]});
			e[0].push_back({i*1000+x[i].a[j],x[i].t[j]});
		}
	}
	while(q--){
		minn=1e18;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<minn<<"\n";
	}
	return 0;
}
