#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int idx,head[maxn];
struct EDGE{ int v,next; }e[maxn*2];
void Insert(int u,int v){
	e[++idx]={v,head[u]},head[u]=idx;
}

int n,m;
namespace subbl{
	#define pir pair<int,int>
	#define mkp make_pair
	#define fi first
	#define se second
	const int INF=1e9;
	int fa[maxn];
	int Find_fa(int x){
		return fa[x]^x?fa[x]=Find_fa(fa[x]):x;
	}
	void Merge(int x,int y){
		int fx=Find_fa(x),fy=Find_fa(y);
		if(fx==fy) return;
		fa[fy]=fx;
	}
	int dis[maxn],a[maxn];
	struct LINE{ int x,y; }eg[maxn];
	priority_queue<pir,vector<pir>,greater<pir> >q;
	void Main(){
		int S=(1<<n),ans=n;
		for(int i=1;i<S;i++){
			for(int j=1;j<=n;j++) a[j]=0,fa[j]=j;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					a[j]=1,cnt++;
				}
			}
			if(cnt>m) continue;
			for(int j=1;j<=m;j++){
				if(a[eg[j].x]&&a[eg[j].y]){
					Merge(eg[j].x,eg[j].y);
				}
			}
			cnt=0;
			for(int j=1;j<=n;j++){
				if(fa[j]==j&&a[j]){
					cnt++;
				}
			}
			if(cnt>2) continue;
//			for(int j=1;j<=n;j++){
//				cout<<a[j]<<" ";
//			}
//			cout<<"\n";
			for(int j=1;j<=n;j++){
				if(!a[j]) dis[j]=INF;
				else dis[j]=0,q.push(mkp(dis[j],j));
			}
			while(!q.empty()){
				int u=q.top().se; int w=q.top().fi; q.pop();
				if(dis[u]<w) continue;
				for(int j=head[u];j;j=e[j].next){
					int v=e[j].v;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push(mkp(dis[v],v));
					}
				}
			}
			int ma=0;
			for(int j=1;j<=n;j++) ma=max(ma,dis[j]);
			ans=min(ans,ma);
		}
		cout<<ans<<"\n";
	}
}

namespace sub2{
	#define pir pair<int,int>
	#define mkp make_pair
	#define fi first
	#define se second
	const int INF=1e9;
	int dep[maxn],a[maxn];
	void Dfs(int x,int fa){
		dep[x]=0;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].v;
			if(v!=fa&&!a[v]){
				Dfs(v,x);
				dep[x]=max(dep[x],dep[v]+1);
			}
		}
	}
	int dis[maxn];
	priority_queue<pir,vector<pir>,greater<pir> >q;
	bool Chk(int len){
		Dfs(1,0);
		int cnt=0;
		for(int i=1;i<=n;i++) a[i]=0;
//		for(int i=1;i<=n;i++){
//			cout<<dep[i]<<" ";
//		}
//		cout<<"\n";
		for(int i=1;i<=n;i++){
			if(dep[i]==len){
				a[i]=1,cnt++;
			}
		}
		if(cnt>m) return false;
//		cout<<"OK\n";
		if(cnt<m){
			Dfs(1,0);
			for(int i=1;i<=n;i++){
				if(dep[i]==len){
					a[i]=1; break;
				}
			}
		}
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<"\n";
		for(int j=1;j<=n;j++){
			if(!a[j]) dis[j]=INF;
			else dis[j]=0,q.push(mkp(dis[j],j));
		}
		while(!q.empty()){
			int u=q.top().se; int w=q.top().fi; q.pop();
			if(dis[u]<w) continue;
			for(int j=head[u];j;j=e[j].next){
				int v=e[j].v;
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(mkp(dis[v],v));
				}
			}
		}
		int ma=0;
		for(int j=1;j<=n;j++) ma=max(ma,dis[j]);
//		cout<<ma<<"\n";
		return ma<=len;
	}
	void Main(){
		int l=0,r=n+1,mid;
//		cout<<Chk(3)<<"\n";
		while(l+1<r){
			mid=(l+r)>>1;
			if(Chk(mid)) r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y,subbl::eg[i]={x,y};
			Insert(x,y),Insert(y,x);
		}
		if(n<=10){
			subbl::Main();
		}
		if(m<=2){
			sub2::Main();
		}
		idx=0;
		for(int i=1;i<=n;i++) head[i]=0;
	}
	return 0;
}
