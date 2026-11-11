#include<bits/stdc++.h>
#define P pair<long long,long long>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,tq,w[N],tmp[N],dis[N],vis[N];
vector<P> a[N];
priority_queue<P,vector<P>,greater<P> > q;
void query(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push(P(0,x));
	while(q.size()){
		int f=q.top().second;
		q.pop();
		if(vis[f]) continue;
		vis[f]=1;
		for(int i=0;i<a[f].size();i++){
			int w=a[f][i].first;
			int t=a[f][i].second;
			if(dis[t]>dis[f]+w){
				dis[t]=dis[f]+w;
				q.push(P(dis[t],t));
			}
		}
	}
	cout<<w[x]+w[y]+dis[y]<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>tq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t;
			cin>>tmp[j]>>t;
			a[tmp[j]+m*i].push_back(P(t,tmp[j]));
			a[tmp[j]].push_back(P(t,tmp[j]+m*i));
			if(j!=1){
				a[tmp[j]+m*i].push_back(P(0,tmp[j-1]+m*i));
				a[tmp[j-1]+m*i].push_back(P(0,tmp[j]+m*i));
			}
		}
	}
	for(int i=1;i<=tq;i++){
		int x,y;
		cin>>x>>y;
		query(x,y);
	}//CCF i BEG you 
	return 0;
}
