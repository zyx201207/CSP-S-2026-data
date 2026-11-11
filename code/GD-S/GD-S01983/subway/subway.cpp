#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],minn,sum;
bool vis[N];
vector<int>G[N];
vector<pair<int,int>>t[N];
void dfs(int step,int end){
	if(step==end){
		minn=min(minn,sum);
		return;
	}
	if(sum>=minn)return;
	for(int i=0;i<G[step].size();i++){
		int u=G[step][i],T=t[step][i].second;
		if(!vis[u]){
			vis[u]=1;
			sum+=T;
			dfs(u,end);
			sum-=T;
			vis[u]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,T;
			cin>>a>>T;
			G[i].push_back(a);
			t[i].push_back({j,T});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		minn=2e9,sum=0;
		dfs(x,y);
		cout<<w[x]+w[y]+minn<<endl;
	}
	return 0;
}
