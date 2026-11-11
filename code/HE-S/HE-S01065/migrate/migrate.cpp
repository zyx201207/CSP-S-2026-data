#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXM=2e6+5;
const int MAXN=5005;
const int INF=0x3f3f3f3f;
typedef pair<ll,bool> PAIR;

int c, T, n;
int dis[MAXN][MAXN];
int dp[MAXN][MAXN];
ll d, x[MAXM];
ll ans;

bool check(int s, int t);
int dfs(int s, int t);
void Asolve();
ll read();

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read(); T=read();
	while(T--){
		n=read(); d=read();
		ans=0;
		
		if(n>10000){ // A
			Asolve();
			printf("%lld\n", ans);
			continue;
		}
		
		memset(dis, -1, sizeof dis);
		memset(dp, -1, sizeof dp);
		
		for(int i=1 ; i<=n ; i++){
			x[i]=read();
		}
		for(int i=1 ; i<=n ; i++){
			for(int j=i+1 ; j<=n ; j++){
				if(check(i,j)) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}

bool check(int s, int t){
	if(x[t]-x[s]<=d) return dp[s][t]=false;
	if(dp[s][t]!=-1) return dp[s][t];
	if(dfs(s,t)==INF) return dp[s][t]=false;
	int mn=INF, dvt, cnt=0;
	for(int v=s+1 ; v<=t ; v++){
		if(x[v]-x[s]>d) break;
		if(check(v,t)){
			if(dfs(v,t)+1==dfs(s,t)) return dp[s][t]=true;
		}
		dvt=dfs(v,t);
		if(dvt<mn){
			mn=dvt;
			cnt=1;
		}
		else if(dvt==mn){
			cnt++;
		}
	}
	return dp[s][t]=(cnt==2);
}

int dfs(int s, int t){
	if(dis[s][t]!=-1) return dis[s][t];
	if(s==t) return dis[s][t]=0;
	int ret=INF;
	for(int v=s+1 ; v<=t ; v++){
		if(x[v]-x[s]>d) break;
		ret=min(ret,dfs(v,t)+1);
	}
	return dis[s][t]=ret;
}

void Asolve(){
	int k=3;
	for(int i=4 ; i<=n ; i++){
		if(x[i]-x[1]<=d) k++;
	}
	if(x[3]-x[1]<=d){
		for(int i=1 ; i<=n-k ; i++){
			ans+=n-(k-1)-i;
		}
	}
	return ;
}

ll read(){
	ll x=0, w=1;
	char c=getchar();
	while(c<'0' || '9'<c){
		if(c=='-') w=-1;
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
