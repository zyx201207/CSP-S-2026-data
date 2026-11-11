#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t;
int n;
long long m;
int dis[N];
map<int,int> mp[N];
vector<int> a[N];
long long b[N];
bool vis[N];
struct node{
	int x;
	int dis;
	bool operator < (const node& i) const {
		return dis>i.dis;
	}
};
void Dijstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) mp[i].clear();
	priority_queue<node> q;
	q.push({st,0});
	vis[st]=true;
	dis[st]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<a[now.x].size();i++){
			int tx=a[now.x][i];
			int ty=now.dis+1;
			mp[tx][ty]++;
			if(!vis[tx] && ty<=dis[tx]){
				q.push({tx,ty});
				vis[tx]=true;
				dis[tx]=ty;
			}
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			a[i].clear();
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(abs(b[i]-b[j])<=m && i!=j){
					a[i].push_back(j);
					a[j].push_back(i);
				}
			}
		int maxn=0;
		for(int i=1;i<=n;i++){
			Dijstra(i);
			for(int j=1;j<=n;j++) if(mp[j][dis[j]]==2) maxn++;
		}
		cout<<maxn/2<<endl;
	}
	return 0;
}
