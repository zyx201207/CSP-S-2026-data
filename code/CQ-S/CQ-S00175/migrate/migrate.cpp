#include <bits/stdc++.h>
#define int long long 
#define N 2000010
#define M 5010
#define inf (int)1e18
#define debug(x) cout<<#x<<" = "<<x<<' '
using namespace std;

struct Node{
	int val,id;
};
bool operator <(Node a,Node b){
	return a.val > b.val;
}

int c,T,n,d;
int x[N];
int dp[M],dis[M],vis[M];
priority_queue<Node> pq; 

void init(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
}

int Dijstra(int st){
	pq.push({0,st});
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=1e9,dp[i]=0;
	dis[st]=0,dp[st]=1;
	
	while(!pq.empty()){
		int id=pq.top().id;pq.pop();
		if(vis[id]) continue;
		vis[id]=1;
		
		for(int r=id+1;r<=n;r++){
			if(x[r]-x[id] > d) break;
//			debug(id),debug(r)<<endl;
			if(dis[id]+1 < dis[r]){
				dis[r]=dis[id]+1,dp[r]=dp[id],
				pq.push({dis[r],r});
			}else{
				if(dis[id]+1 == dis[r])
					dp[r]=min(inf,dp[r]+dp[id]);
				}
//			debug(id),debug(r),debug(dp[r]),debug(dis[id]),debug(dis[r])<<endl;
		}
	}
	
	int res=0;
	for(int i=st;i<=n;i++)
		if(dp[i] == 2)
			res++;
	return res;
}

int solve(){
	int res=0;
	if(c == 11 || c == 12){
		int len=d/(x[2]-x[1]),res=0;
		if(len == 0) return 0;
		for(int r=1;r<=n;r++){
			if((r-1) %len == 0) continue;
			int dis=(r-2)/len+1,st=(dis-2)*len+1;
//			debug(st),debug(dis),debug(r)<<endl;
			if(dis == 1) continue;
			if((st+len)-(r-len)+1 == 2) res++;
		}
		
		return res;
//		return n-len-1;
	}
	
	for(int l=1;l<=n;l++) res+=Dijstra(l);
	return res;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		init();
		cout<<solve()<<"\n";
	}
	return 0;
}
