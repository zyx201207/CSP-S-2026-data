#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int cnt;
struct node{
	int cnt=0,to[505],id,w1,w2[505];//w1:地铁口到站厅时间 w2:站厅到站台时间 
}a[505];
long long ans[505];
long long f(int x,int y){
	queue<int>q;
	int dis[505];
	for(int i=1;i<=505;i++){
		dis[i]=0x3f3f3f3f;
	}
	q.push(x);
	dis[x]=0;
	while(q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=a[u].cnt;i++){
			int v=a[u].to[i];
			if(dis[v]==0x3f3f3f3f){
				q.push(v);
				if(a[u].id!=a[v].id){
					int sum=cnt;
					dis[v]=min(dis[v],dis[u]+a[u].w2[a[u].id]+a[u].w2[a[v].id]);
				}else{
					dis[v]=min(dis[v],dis[u]+a[u].w2[a[u].id]);
				}
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].w1;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a1,t1;
			cin>>a1>>t1;
			a[a1].id=++cnt;
			a[a1].w2[cnt]=t1;
			a[a1-1].to[a[a1-1].cnt]=a1;
		}
	}
	int w=q;
	while(w--){
		int u,v;
		cin>>u>>v;
		//ans[w]+=a[u].w1+a[v].w1;
		
		ans[w]+=f(u,v);cout<<ans[w]<<" ";
	}
	for(int i=q;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}

