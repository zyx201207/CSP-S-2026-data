#include<bits/stdc++.h>
#define int long long
const int N=505;
const int M=505;
using namespace std;
int a[N],w[M],dis[M],vis[N];
int b[N][M],v[N][M],V[M][M];
int ans;
int c,n,m,d,T;
struct node{
	int id,w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};
priority_queue<node> q;
void dfs(int st,int nd){
	for(int i=1;i<=m;i++) dis[i]=1e18,vis[i]=0;
	while(!q.empty()) q.pop();
	q.push(node{st,0});
	dis[st]=0;
	while(!q.empty()){
//		cout<<"a";
		int x=q.top().id;
		q.pop();
		
		if(x==nd){
			ans=dis[x]+w[st]+w[nd];
//			cout<<st<<" "<<nd<<"\n";
			return ;
		}
		if(vis[x]) continue;
		vis[x]=1;
//		cout<<x<<' ';
		for(int i=1;i<=m;i++){
			if(x==i) continue;
			if(dis[x]+V[x][i]<dis[i]){
				dis[i]=dis[x]+V[x][i];
				q.push(node{i,dis[i]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			V[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=a[i];j++){
			scanf("%lld%lld",&b[i][j],&v[i][j]);
		}
		for(int j=1;j<=a[i];j++){
			for(int k=i+1;k<=a[i];k++){
//				cout<<j<<" "<<k<<"\n";
				if(j==k) continue;
				int t1=b[i][j],t2=b[i][k];
				int t=v[i][j]+v[i][k];
				if(t<V[t1][t2]){
					V[t1][t2]=t;
					V[t2][t1]=t;
				}
			}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<V[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(T--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		dfs(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}

