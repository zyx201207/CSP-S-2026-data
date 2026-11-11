#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+10;

int n,d,x[N],l[N];
int f[N],g[N];

int dis[N],cnt[N],d_[N],d1[N];

vector<int> son[N];

void solve1(){
	
	for(int i=1;i<=n;i++) son[i].clear(),d1[i]=0;
	
	for(int i=1;i<=n;i++){
		
		for(int j=i+1;j<=n;j++){
			
			if(x[j]-x[i]<=d) son[j].push_back(i);
			
		}
		
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		
		queue<int> q;
		
		for(auto x:son[i]) d1[x]++;
		
		for(int j=1;j<=n;j++) d_[j]=d1[j],dis[j]=1e9,cnt[j]=0;
		
		dis[i]=0,cnt[i]=1; q.push(i);
		
		while(!q.empty()){
			
			int u=q.front(); q.pop();
			
			for(auto v:son[u]){
				
				if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,cnt[v]=cnt[u];
				else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
				
				if(--d_[v]==0) q.push(v);
				
			}
			
		}
		
		for(int j=1;j<i;j++) ans+=(cnt[j]==2);
		
	}
	
	cout<<ans<<'\n';
	
}

void solve(){
	
	cin>>n>>d;
	
	for(int i=0;i<=n+2;i++) f[i]=0,g[i]=0,l[i]=0;
	
	for(int i=1;i<=n;i++) cin>>x[i];
	
	if(n<=5000) {solve1();return ;}
	
	int now=1;
	
	for(int i=1;i<=n;i++) {
		
		while(now<i&&x[i]-x[now]>d) now++; l[i]=now;
		
	}
	
	for(int i=1;i<=n-1;i++){
		
		int x=l[i],y=l[i+1],z=l[i+2];
		
		if(i==l[i]) continue; if(!z) z=i;
		
		if(x==z) continue;
		
		if(y<i) f[i]=y-x; else f[i]=i-x; 
		
		if(y<i) g[i]=min(z-y,i-y);
		
		f[i]+=f[l[i]]*(x!=y);
			
		g[i]+=f[l[i]]*(x==y)+g[l[i]]*(x!=y);
		
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++) ans+=g[l[i]];
	
	cout<<ans<<'\n';
	
}

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int c,T; cin>>c>>T;
	
	while(T--) solve();
	
}

/*
0 1
6 3
0 1 2 3 4 7
*/
