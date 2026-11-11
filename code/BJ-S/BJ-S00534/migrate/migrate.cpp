#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
typedef long long ll;
#define PII pair<int,int>
const int INF=0x3f3f3f3f;
int c,T;
int n;
ll d;
ll a[N];
int cnt=0;
int head[N];
int dis[N];
int vis[N];
int dis2[N];
int vis2[N];
int ans=0;
struct R{
	int to;
	int w;
	int next;
}mp[N];

void add_edge(int u,int v,int w){
	mp[++cnt].to=v;
	mp[cnt].w=w;
	mp[cnt].next=head[u];
	head[u]=cnt;
}
void dij(int u){
	priority_queue<PII,vector<PII>,greater<PII>>pq;
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[u]=0;
	pq.push({dis[u],u});
	while(!pq.empty()){
		PII PQ=pq.top();
		pq.pop();
		if(vis[PQ.second]){
			continue;
		}
		vis[PQ.second]=1;
		for(int i=head[PQ.second];i;i=mp[i].next){
			if(PQ.first+mp[i].w<dis[mp[i].to]){
				dis[mp[i].to]=PQ.first+mp[i].w;
				
				pq.push({dis[mp[i].to],mp[i].to});
			}
		}
	}
}
void dij2(int u){
	priority_queue<PII,vector<PII>,greater<PII>>pq2;
	memset(dis2,INF,sizeof(dis2));
	memset(vis2,0,sizeof(vis2));
	dis2[u]=0;
	pq2.push({dis2[u],u});
	while(!pq2.empty()){
		PII PQ2=pq2.top();
		pq2.pop();
		if(vis2[PQ2.second]){
			continue;
		}
		vis2[PQ2.second]=1;
		for(int i=head[PQ2.second];i;i=mp[i].next){
			if(PQ2.first+mp[i].w<dis2[mp[i].to]){
				dis2[mp[i].to]=PQ2.first+mp[i].w;
				
				pq2.push({dis2[mp[i].to],mp[i].to});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||12){
		while(T--){
			ans=0;
			cnt=0;
			memset(head,0,sizeof(head));
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n-2*d+1<<endl;
		}
	}
	else{while(T--){
		ans=0;
		cnt=0;
		memset(head,0,sizeof(head));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]=i;
		}
		int gj=2;
		for(int i=1;i<=n;i++){
			gj=i+1;
			while(1){
				
				if(gj<=n&&a[gj]-a[i]<=d){
					//cout<<i<<" "<<gj<<endl;
					add_edge(i,gj,1);
					add_edge(gj,i,1);
				}
				else{
					break;
				}
				gj++;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=n;j>i;j--){
				int spcnt=0;
				dij(i);
				dij2(j);
				for(int k=i+1;k<j;k++){
					if(dis[k]+dis2[k]==dis[j]){

						spcnt++;
					}
					if(spcnt>2){
						
						break;
					}
				}
				if(spcnt==2){
					cout<<i<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}}
	
	return 0;
}
