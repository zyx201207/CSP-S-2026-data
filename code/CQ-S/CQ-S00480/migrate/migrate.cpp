#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3,M=2.5e7,INF=1e18;
int c,t,n,d,a[N+5];
struct graph{
	signed tot,head[N+5],nxt[M+5],to[M+5];
	inline void link(int a,int b){
		nxt[++tot]=head[a];
		head[a]=tot;
		to[tot]=b;
	}
	inline void init(){
		tot=0;
		for(int i=1;i<=n;i++) head[i]=0;
	}
}T;
int dis[N+5],cnt[N+5],ans;
queue<int> q;
inline void bfs(int s){
	ans=0;
	for(int i=1;i<=n;i++) dis[i]=INF,cnt[i]=0;
	dis[s]=0,cnt[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=T.head[x];i;i=T.nxt[i]){
			int v=T.to[i];
//			cout<<v<<'\n';
			if(dis[v]==INF) dis[v]=dis[x]+1;
			if(dis[x]+1==dis[v]){
				q.push(v);
				cnt[v]++;
				if(cnt[v]==2){
					ans++;
//					cout<<"appear:"<<s<<' '<<v<<'\n';
				}
				if(cnt[v]==3){
					ans--;
//					cout<<"disappear:"<<s<<' '<<v<<'\n';
				}
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t; 
	while(t--){
		cin>>n>>d;
		T.init();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int l=i-1;
			while(l>0&&a[i]-a[l]<=d){
				T.link(i,l);
				l--;
			}
			l=i+1;
			while(l<=n&&a[l]-a[i]<=d){
				T.link(i,l);
				l++;
			}
		}
		int num=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			num+=ans;
		}
		cout<<num/2<<'\n';
	}
	return 0;
} 
