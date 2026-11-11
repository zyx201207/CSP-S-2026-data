#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10,inf=1e18+10;

ll c,t,n,k,u,v,dist[N],ans=inf,cnt;
vector<ll> e[N];
bool cs[N],vis[N];
queue<ll> Q;

inline void dfs2(ll u,ll fa){
	
	if(!cs[fa]&&cs[u]) cnt++;
	for(auto v:e[u]) if(v!=fa) dfs2(v,u);
	
	return;
}

inline void check(){
	
	cnt=0,dfs2(1,0);
	if(cnt==0||cnt>2) return;
	
	for(int i=1;i<=n;i++) dist[i]=inf,vis[i]=false;
	for(int i=1;i<=n;i++) if(cs[i]) vis[i]=true,dist[i]=0,Q.push(i);
	
	while(!Q.empty()){
		
		ll u=Q.front();Q.pop();
		for(auto v:e[u]) if(!vis[v]) vis[v]=true,dist[v]=dist[u]+1,Q.push(v);
	}
	
	ll op=0;
	for(int i=1;i<=n;i++) op=max(op,dist[i]);
	
	return ans=min(ans,op),void();
}

inline void dfs(ll u,ll cnt){
	
	if(cnt>k) return;
	if(u==n+1&&cnt==k) return check();
	else if(u>n) return;
	
	cs[u]=true,dfs(u+1,cnt+1);
	cs[u]=false,dfs(u+1,cnt);
	
	return;
}

inline bool check2(ll mid){
	
	ll opl=k/2,opr=(k&1)?k/2+1:k/2;
	
	ll L=mid,R=n/2+2-mid;
	ll dis=(R-L)/2+1;
	
	return dis<=mid;
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		
		if(c>=13&&c<=14){
			
			if(k>n/2) cout<<"1\n";
			else{
				
				ll l=1,r=n/2+1,mid;
				while(l<=r){
					
					mid=(l+r)>>1;
					if(check2(mid)) r=mid-1;
					else l=mid+1;
				}
				
				cout<<l<<'\n';
			}
		}
		else if(n<=100){
			
			ans=inf,dfs(1,0);
			cout<<ans<<'\n';
		}
		else cout<<n/2<<'\n';
		
		for(int i=1;i<=n;i++) e[i].clear();
	}
	
	return 0;
}

/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
