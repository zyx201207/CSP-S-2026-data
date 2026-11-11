#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef pair<long long,long long> pi;
int c,n,m,d,q;
vector<pi> e[N+1000];
long long w[N],dis[505][505];
void dij(int st){
	priority_queue<pi,vector<pi>,greater<pi>> q;
	vector<long long> dist(m+n+10,0x3f3f3f3f3f3f3f3f);
	vector<bool> flag(m+n+10,0);
	q.push({0,st+m});
	dist[st+m]=0;
	while(!q.empty()){
		auto p=q.top();q.pop();
		int x=p.second;
		if(flag[x]) continue;
		flag[x]=1;
		for(auto _:e[x]){
			int y=_.first;
			long long w=_.second;
			if(dist[y]>dist[x]+w){
				dist[y]=dist[x]+w;
				q.push({dist[y],y});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[st][i]=min(dis[st][i],dist[i+m]);
		dis[i][st]=min(dis[i][st],dist[i+m]);
	}
	return;
}
long long W;
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
//	freopen("subway5.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;cin>>x>>w;
			W=w;
			e[x].push_back({m+i,w});
			e[m+i].push_back({x,w});
		}
	}
	memset(dis,0x3f,sizeof dis);
	if(c>=12 && c<=19){
		for(int i=1;i<=m;i++){
			vector<int> tmp;
			for(auto p:e[i]) tmp.push_back(p.first-m);
			int siz=(int)tmp.size();
			for(int j=0;j<siz;j++){
				for(int k=0;k<siz;k++){
					if(j==k){dis[tmp[j]][tmp[k]]=0;continue;}
					dis[tmp[j]][tmp[k]]=2*W;
				}
			}
		}
		for(int l=1;l<=n;l++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	}
	else{
		for(int i=1;i<=n;i++) dij(i);
	}
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto px:e[x]){
			int u=px.first;
			long long w1=px.second;
			for(auto py:e[y]){
				int v=py.first;
				long long w2=py.second;
				ans=min(ans,dis[u-m][v-m]+w1+w2+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//84

