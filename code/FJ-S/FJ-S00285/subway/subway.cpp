#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,n,m,d,qq,tot;
long long dis[N];
struct Edge{
	int to;
	long long w;
	bool operator < (const Edge xx)const{
		return w>xx.w;
	}
}; 
vector <Edge> e[N];
priority_queue<Edge> q;
void dij(int s){
	for(int i=1;i<=tot;i++) dis[i]=0x3f3f3f3f3f3f3f3f;
	dis[s]=0;
	Edge now;
	now.to=s,now.w=0ll;
	q.push(now);
	while(!q.empty()){
		int u=q.top().to;
		long long len=q.top().w;
		q.pop();
		for(int i=0;i<(int)e[u].size();i++){
			int v=e[u][i].to;
			long long w=e[u][i].w;
			if(len+w<dis[v]){
				dis[v]=len+w;
				now.to=v,now.w=dis[v];
				q.push(now);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qq;
	long long x;
	for(int i=1;i<=m;i++){
		cin>>x;
		Edge now;
		now.to=i*2+1,now.w=x;
		e[i*2].push_back(now);
		now.to=i*2;
		e[i*2+1].push_back(now);
	}
	tot=m*2+2;
	int k,a;
	long long t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			Edge now;
			now.to=tot,now.w=t;
			e[a*2+1].push_back(now);
			now.to=a*2+1;
			e[tot].push_back(now);
			if(j>1){
				now.to=tot,now.w=0ll;
				e[tot-1].push_back(now);
				now.to=tot-1;
				e[tot].push_back(now);
			}
			tot++;
		}
	}
	int xx,yy;
	while(qq--){
		cin>>xx>>yy;
		dij(xx*2);
		cout<<dis[yy*2]<<'\n';
	}
	return 0;
}

