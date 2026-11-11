#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,Q;
const int N=500,M=2e4;
int to[5*M],nxt[5*M],h[M+M+10];
ll W[5*M];
int cnt;
void add(int x,int y,ll w){
	++cnt;
	to[cnt]=y;
	W[cnt]=w;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
ll v[M+10];
ll dp[M+M+10];
ll Dp[(int)1e4+10][(int)1e4+10];
map<ll,ll>hs;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	int k,a;
	int t;
	int Cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		int last=-1;
		while(k--){
			cin>>a>>t;
			Cnt++;hs[i*m+a]=Cnt;
			if(last==-1){
				add(Cnt,a,t);
				add(a,Cnt,t);
			}
			else{
				add(Cnt,a,t);
				add(a,Cnt,t);
				add(Cnt,Cnt-1,0);
				add(Cnt-1,Cnt,0);
			}
			last=a;
		}
	}
	for(int s=1;s<=m;s++){
		priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>> >q;
		memset(dp,0x3f,sizeof dp);
		dp[s]=0;
		q.push({0,s});
		while(!q.empty()){
			auto[x,u]=q.top();q.pop();
			if(dp[u]!=x) continue;
			for(int i=h[u];i;i=nxt[i]){
				int v=to[i];ll w=W[i];
				if(dp[v]>dp[u]+w){
					dp[v]=dp[u]+w;
					q.push({dp[v],v});
				}
			}
		}	
		for(int i=1;i<=m;i++) Dp[s][i]=dp[i];
	}
	while(Q--){
		ll l,r;cin>>l>>r;
		cout<<v[l]+Dp[l][r]+v[r]<<"\n";
	}
	return 0;
}
