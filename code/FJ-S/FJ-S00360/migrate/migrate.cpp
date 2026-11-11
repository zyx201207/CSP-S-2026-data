#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e3+5;
constexpr int M=2.5e7+5; 
int c,t,n;
long long d,x[N];
int head[N],tot,to[M],nxt[M];
void add(int u,int v){
	to[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
struct node{
	int u,dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
int dis[N];
long long ans;
unsigned long long cnt[N];
void dij(int st){
	memset(dis+1,0x3f,sizeof(int)*n);
	memset(cnt+1,0,sizeof(unsigned long long)*n); 
	priority_queue<node>q;
	q.push({st,0}),dis[st]=0,cnt[st]=1;
	while(!q.empty()){
		int u=q.top().u,dist=q.top().dis;
		q.pop();
		if(dist!=dis[u])continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dist+1<dis[v]){
				dis[v]=dist+1;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}else if(dist+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==2){
			ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		tot=0;
		memset(head+1,0,sizeof(int)*n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					add(i,j);
					add(j,i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
