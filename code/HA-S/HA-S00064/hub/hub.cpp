#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
int n,k;
int c[N],up[N][25],dep[N],hu=0,g[N];
vector<int> h[N];
void dp(int x,int fa){
	//cout<<x<<":";
	dep[x]=dep[fa]+1;
	up[x][0]=fa;
	for(int i=1;i<=21;i++) up[x][i]=up[up[x][i-1]][i-1];
	for(auto to:h[x]){
		if(to!=fa) dp(to,x);
	}
}
int ops[4005][4005];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=21;i>=0;i--) if(dep[x]-(1<<i)>=dep[y]) x=up[x][i];
	if(x==y) return x;
	for(int i=21;i>=0;i--){
		if(up[x][i]!=up[y][i]) x=up[x][i],y=up[y][i];
	}
	return up[x][0];
}
int b[N],mi=INT_MAX;
void dfs(int l){
	//cout<<l<<":";
	if(l==k){
		int sum=INT_MIN;
		for(int j=1;j<=hu;j++) {
			//cout<<g[j]<<" ";
		//	cout<<"\n";
			int ans=INT_MAX;
			for(int i=1;i<=n;i++){
			if(i==j) continue;
				//cout<<i<<" "<<g[j]<<" "<<lca(i,g[j])<<"\n";
				ans=min(ans,dep[i]-dep[lca(i,g[j])]+dep[g[j]]-dep[lca(i,g[j])]);
				//cout<<i<<"-"<<g[j]<<":"<<ans<<"\n";
			}
			sum=max(sum,ans);
		}
		//cout<<sum<<"::"<<mi<<"\n";
		mi=min(mi,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			int flag=0;
			for(auto to:h[i]){
				if(b[to]==1){
					flag=1;
					break;
				}
			}
			if(flag) continue;
			b[i]=1;
			g[++hu]=i;
			dfs(l+1);
			b[i]=0;
			hu--;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(b,0,sizeof b);
		memset(ops,0,sizeof ops);
		mi=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++) h[i].erase(h[i].begin(),h[i].end());
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			//add(u,v);
			//add(v,u);
			h[u].push_back(v);
			h[v].push_back(u);
		}
		dep[1]=0,dp(1,0),dfs(0);
		cout<<mi<<"\n";
	}
	return 0;
}

