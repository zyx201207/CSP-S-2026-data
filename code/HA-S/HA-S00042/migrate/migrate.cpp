#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
struct node{
	ll x,dis,s;
	bool operator<(const node& a) const {return a.dis<dis;}
};
ll c,t,n,d,X[N],dis[N],sum[N],cnt;
priority_queue<node> q;
vector<int> v[N];

void dijkstra(int x){
	memset(dis,127,sizeof(dis));
	q.push({x,0,1});dis[x]=0;sum[x]=1;
	while(!q.empty()){
		node now=q.top();q.pop();
		for(int i=0;i<v[now.x].size();i++){
			int u=v[now.x][i];
			if(dis[u]>dis[now.x]+1){
				dis[u]=dis[now.x]+1;sum[u]=sum[now.x];
				q.push({u,dis[u],sum[u]});
			}else if(dis[u]==dis[now.x]+1) sum[u]+=sum[now.x];
		}
	}
	for(int i=x;i<=n;i++) if(sum[i]==2) cnt++;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) cin>>X[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(X[j]-X[i]<=d) v[i].push_back(j);
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++) dijkstra(i);
		cout<<cnt<<endl;
	}
	return 0;
}
