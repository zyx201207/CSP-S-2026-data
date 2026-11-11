#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+5,INF=1e18;
int c,T,n,d,x[N],ans,in[305],dis[305],cnt[305];
vector<int> G[305];
//int Sum[3][N<<2],Tag[3][N<<2];

//int get_pos(int L,int R,int X,int pos=-1){
//	while(L<=R){
//		int mid=(L+R)>>1;
//		if(X>=x[mid])
//			L=mid+1,pos=mid;
//		else
//			R=mid-1;
//	}
//	return pos;
//}

void topo(int S){
	queue<int> q;
	memset(dis,0x7f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	memset(in,0,sizeof in);
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=S;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[j]<=x[i]+d) G[i].push_back(j),in[j]++;
	q.push(S),dis[S]=0,cnt[S]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:G[u]){
			if(dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,cnt[v]=cnt[u];
			else if(dis[v]==dis[u]+1)
				cnt[v]+=cnt[u];
			if(!--in[v])
				q.push(v);
		}
	}
	for(int i=S+1;i<=n;i++)
		if(cnt[i]==2) ans++;
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	if(c<=6){
		while(T--){
			cin >> n >> d,ans=0;
			memset(in,0,sizeof in);
			for(int i=1;i<=n;i++)
				cin >> x[i];
			for(int i=1;i<=n;i++)
				topo(i);
			cout << ans <<"\n";
		}
		return 0;
	}
	return 0;
}
