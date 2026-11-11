#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000005
ll c,T,n,d,answer;
ll a[N];
ll R[N];
vector<ll>g[N];
ll dp[N][3];//连续末尾有恰好1个1，>=2个1，>=1个2 
void dfs(ll u,ll father){
	if(father==0){
		; 
	}
	else if(R[father]==father){
		;
	}
	else{
		if(R[father]==R[father-1]){
			dp[u][2]=0;
		}
		else{
			dp[u][2]=R[father]-R[father-1]+dp[father][2];
		}
		if(R[father-1]==R[father]){
			dp[u][0]=0;
		}
		else if(R[father-1]+1==R[father]){
			dp[u][0]=dp[father][0];
		}
		else{
			dp[u][0]=dp[father][1];
		}
		if(u+1!=father){
			if(R[father-1]==R[father]){
				if(R[father-2]==R[father-1]){
					;
				}
				else{
					dp[u][1]=(R[father-1]-R[father-2])+dp[father][2];
				}
			}
			else if(R[father-1]+1==R[father]){
				dp[u][1]=dp[father][0]+(R[father-1]-R[father-2]);
			}
			else{
				dp[u][1]=dp[father][1]+(R[father-1]-R[father-2]);
			}
		}
	}
	if(father==u+1)answer+=dp[u][0];
	else answer+=dp[u][1];
	for(ll to:g[u]){
		dfs(to,u);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate7.in","r",stdin);
//	freopen("joker.out","w",stdout);
	clock_t t0=clock();
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
			dp[i][0]=dp[i][1]=dp[i][2]=0;
		}
		ll pos=n;
		for(ll i=n;i>=1;i--){
			while(a[pos]-a[i]>d)pos--;
			if(pos==i){
				;
			}
			else{
				g[pos].push_back(i);
			}
			R[i]=pos;
		}
		answer=0;
		for(ll i=1;i<=n;i++){
			if(R[i]==i){
				dfs(i,0);
			}
		}
		cout<<answer<<endl;
	}
	fprintf(stderr,"time=%.3fs\n",(double)(clock()-t0)/CLOCKS_PER_SEC);
	return 0;
}
