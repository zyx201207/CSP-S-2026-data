#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
struct node{
	int id,v;
	inline bool operator <(const node &tmp) const{
		return tmp.v<v;
	}
};
int cid,T,n;
ll d,a[N],ans;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline void solve1(){
	ans=0;
	int dis[N]={},cnt[N]={};
	vector<int> g[N];
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>d) break;
			g[j].push_back(i);
		}
	for(int S=1;S<=n;S++){
		for(int i=S;i<=n;i++) dis[i]=1e9,cnt[i]=0;
		priority_queue<node> q;
		q.push({S,0});
		dis[S]=0;
		cnt[S]=1;
		while(!q.empty()){
			int u=q.top().id;
			q.pop();
			for(int v:g[u]){
				if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,cnt[v]=cnt[u],q.push({v,dis[v]});
				else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			}
		}
		for(int i=S+1;i<=n;i++)
			if(cnt[i]==2) ans++;
	}
	printf("%lld\n",ans);
}
inline void solve2(){
	int pos=0;
	for(int i=2;i<=n;i++)
		if(a[i]-a[1]>d){
			pos=i;
			break;
		}
	if(pos<=3) printf("0\n");
	else printf("%d\n",n-pos);
}
inline void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(cid<=10) solve1();
	if(cid>=11 && cid<=12) solve2();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=read(),T=read();
	while(T--) solve();
	return 0;
}
