#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pint;
const int N=2e6+114;
int T;
int ans;
int n,d;
int x[N],to1[N],to2[N];
int cnt[N],cnt2[N][2];
struct Edge{
	int v,nxt;
	Edge(){}
	Edge(int v_,int nxt_):v(v_),nxt(nxt_){}
};
int head[N],tot;
Edge e[N];
inline void ins(int u,int v){
	e[++tot]=Edge(v,head[u]);
	head[u]=tot;
}
int F[N],G[N],H[N];
void dfs(int u,int isrt,int s){
	if(!isrt){
		int _=0;
		if(to1[to2[u]]==u){
			F[u]=F[to2[u]]+cnt[u];
			G[u]=G[to2[u]]+cnt2[u][1];
			int a=to2[u];
			int b=to2[a];
			_+=G[a];
				if(b!=a){
					if(to1[b]==a) _+=s;
					else if(to1[b]==a-1){
						_+=F[b];
						if(to1[a-1]==u) s=F[b];
						else s=0;
					}
					else s=0;
				}
			if(a-1>u){
				_+=cnt[a-1];
			}
		}
		else{
			int a=to2[u];
			int b=to2[a];
			_+=G[a];
				if(b!=a){
					if(to1[b]==a) _+=s;
					else if(to1[b]==a-1){
						_+=F[b];
						if(to1[a-1]==u) s=F[b];
						else s=0;
					}
					else s=0;
				}
			if(a-1>u){
				_+=cnt[a-1];
			}
			else s=0;
		}
//		if(T==15){
//		
//		cout << u << " " << s << " " << _ << endl;
//		}
		ans+=_;
	}
	for(int i=head[u];i;i=e[i].nxt) dfs(e[i].v,0,s);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid;
	cin >> cid >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1;i<=n;++i) cin >> x[i];
		for(int i=1,j=1;i<=n;++i){
			while(x[i]-x[j]>d) ++j;
			to1[i]=j;
		}
		for(int i=n,j=n;i>=1;--i){
			while(x[j]-x[i]>d) --j;
			to2[i]=j;
		}
		for(int i=1;i<=n;++i) cnt[i]=0;
		for(int i=1;i<=n;++i) if(to1[i]<i) ++cnt[to1[i]];
		for(int i=1;i<=n;++i) cnt2[i][0]=cnt2[i][1]=0;
		for(int i=1;i<=n;++i){
			if(to1[i]<i){
				cnt2[to1[i]][1]=cnt2[to1[i]][0];
				cnt2[to1[i]][0]=cnt[i];
			}
		}
		tot=0;
		for(int i=1;i<=n;++i) head[i]=0;
		for(int i=1;i<=n;++i){
			if(to2[i]>i) ins(to2[i],i);
		}
		for(int i=1;i<=n;++i) F[i]=0,G[i]=0;
		ans=0;
		for(int i=n;i>=1;--i){
			if(to2[i]==i) dfs(i,1,0);
		}
//		if(T==15){
//			for(int i=1;i<=n;++i) cout << to1[i] << " ";
//			cout << endl;
//			for(int i=1;i<=n;++i) cout << to2[i] << " ";
//			cout << endl;
//		}
		cout << ans << endl;
	}
	return 0;
}
