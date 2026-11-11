#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
int cc,T,n,st,ed,dis[N],cnt[N];
ll d,x[N],c,ans,tmp;
int e[N],ne[N],h[N],idx;
bool vis[N];
void add(int u,int v){
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
void dj(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i!=-1;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
//				cout<<v<<" ";
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&cc,&T);
	while(T--){
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		bool ff=0;
		for(int i=2;i<=n;i++){
			if(x[2]-x[1]>d){
				ff=1;
				break;
			}
		}
		if(ff==1){
			printf("0\n");
			continue;
		}
		if(cc==11||cc==12){
			c=x[2]-x[1];
			if(c==0){
				printf("0\n");
				continue;
			}
			tmp=d/c;
			if(tmp==0||tmp==1){
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(d%c==0){
					if(i+tmp<=n&&i+2*tmp-1<=n) ans++;
				}
				else{
					if(i+tmp<=n&&i+2*tmp-1<=n) ans++;
				}
//				if(i+tmp<=n&&i+2*tmp-1<=n) ans++;
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++) h[i]=-1;
		idx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) add(i,j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=2*n,vis[j]=0,cnt[j]=1;
			dj(i); 
			for(int j=i+1;j<=n;j++){
//				cout<<cnt[j]<<" ";
				if(cnt[j]==2) ans++;
			}
//			cout<<endl;
		}
		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++){
//			st=i;
//			int cnt=0;
//			for(int j=i+1;j<=n;j++){
//				if(x[j]-x[j-1]>d) break;
//				if(j>ed){
//					st=j;ed=j;
//					while(ed<n&&x[ed+1]-x[st]<=d) ed++;
//					cnt=1;
//					continue;
//				}
//				if(x[j+(ed-st)])
//			}
//		}
	}
	return 0;
} 
