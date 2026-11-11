#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> PIL;
typedef pair<long long,int> PII;
int op,n,m,d,Qqt;
long long w[500010],ans;
int k;
long long dis[500010];
vector<PIL> g[500010];
bool vis[500010];
long long b[500010],cnt1=0,cnt2,v[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>op>>n>>m>>d>>Qqt;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cnt1=0,cnt2=0;
		for(int j=1;j<=2*k;j++){
			if(j%2==1){
				cin>>b[++cnt1];
			}else{
				cin>>v[++cnt2];
			}
		}
		for(int j=1;j<=cnt1;j++){
			for(int k=j+1;k<=cnt1;k++){
				g[b[j]].push_back({b[k],v[k]+v[j]});
				g[b[k]].push_back({b[j],v[k]+v[j]});
			}
		}
	}
	while(Qqt--){
		int x,y;
		cin>>x>>y;
		ans=0;
		ans+=w[x]+w[y];
	priority_queue<PII,vector<PII>,greater<PII> > q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
    while(!q.empty())q.pop();
	q.push({0,x});
	vis[x]=1;
	dis[x]=0;
	while(!q.empty()){
		auto tt=q.top();
		q.pop();
		int u=tt.second;
		vis[u]=1;
		for(auto nt:g[u]){
			int to=nt.first;
			long long ww=nt.second;
			if(!vis[to]&&(dis[to]>dis[u]+ww)){
				dis[to]=min(dis[u]+ww,dis[to]);
				q.push({dis[to],to});
			}
		}
	}
	    ans+=dis[y];
	    cout<<ans<<endl;
	}
	return 0;
}
