#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int MAXN=505,MAXM=500005,MAXD=25;
struct Node{
	int u;
	ll t;
	bool operator<(const Node &o)const{
		return u<o.u;
	}
};
int c,n,m,d,q;
ll cost[MAXN][MAXN],f[MAXN][MAXN],W[MAXM];
vector<Node> A[MAXM];
void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(i!=j) f[i][j]=cost[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		for(Node a:A[i]){
			for(Node b:A[i]){
				if(a.u!=b.u){
					cost[a.u][b.u]=min(cost[a.u][b.u],a.t+b.t);
					if(f[a.u][b.u]>cost[a.u][b.u])
						f[a.u][b.u]=cost[a.u][b.u];
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				ll val=f[i][k]+f[k][j];
				if(f[i][j]>val) f[i][j]=val;
			}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			ll t; cin>>a>>t;
			A[a].push_back({i,t});
		}
	}
	build();
	while(q--){
		int s,t; cin>>s>>t;
		ll res=1e18;
		for(Node ks:A[s]){
			for(Node kt:A[t]){
				int su=ks.u,tu=kt.u;
				res=min(res,W[s]+W[t]+f[su][tu]+ks.t+kt.t);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
