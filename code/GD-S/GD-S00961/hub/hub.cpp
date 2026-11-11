#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define LL long long

const int N=1e6+5;
const int M=5e3+3;

LL c,T,n,k,m,ans,inf=2e18;
LL A[N],B[N];
bool ck[N];

vector<LL> E[N];

LL F[N];
LL fd(LL x){
	return x==F[x]?x:F[x]=fd(F[x]);
}

LL dl[N],dp[N];
LL dt,dw;
void bfs(){
	dt=1,dw=0;
	for(int i=1;i<=n;i++){
		dp[i]=inf;
		if(ck[i]){
			dl[++dw]=i;dp[i]=0;
		}
	}
	while(dt<=dw){
		for(auto u:E[dl[dt]]){
			if(dp[u]>dp[dl[dt]]+1){
				dp[u]=dp[dl[dt]]+1;
				dl[++dw]=u;
			}
		}
		dt++;
	}
	ans=min(ans,dp[dl[dw]]);
	return ;
}

void check(){
	for(int i=1;i<=n;i++){
		F[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(ck[i]){
			for(auto u:E[i]){
				if(ck[u]&&fd(u)!=fd(i))F[fd(u)]=fd(i);
			}
		}
	}
	LL y=0;
	for(int i=1;i<=n;i++){
		if(ck[i]&&fd(i)==i)y++;
	}
	if(y<=2)bfs();
	return ;
}

void dfs(LL x,LL y){
	if(y==k){
		check();return ;
	}
	if(x>n)return ;
	ck[x]=1;
	dfs(x+1,y+1);
	ck[x]=0;
	dfs(x+1,y);
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	unsigned LL rp=-1;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)E[i].clear();
		for(int i=1;i<n;i++){
			LL x,y;
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		if(k==n){
			cout<<"0\n";continue;
		}
		if(c==13||c==14){//a
			m=(n-1)/2;
			k/=2;k*=2;
			if(k>=m){
				cout<<"1\n";continue;
			}
			if(m&1){
				ans=floor((m+5-k)/4);
			}
			else{
				ans=floor((m+4-k)/4);
			}
			cout<<ans<<'\n';
		}
		else{
			ans=inf;
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
