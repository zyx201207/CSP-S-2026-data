#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
bool bj[1000006];
int ans,dep[1000005],dp[1000005][30],n,k;
vector<int> v[1000006];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=21;i>=0;i--){
		if(dep[dp[x][i]]>dep[y]){
			x=dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i=21;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return x;
}
void dfs2(int id,int fa){
	dep[id]=dep[fa]+1;
	dp[id][0]=fa;
	for(int to:v[id]){
		if(to!=fa){
			dfs2(to,id);
		}
	}
} 
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)]-2;
}
void dfs1(int id,int num){
	if(num>k)return;
	if(id==n+1&&num==k){
		int an;
		for(int i=1;i<=n;i++){
			an=0;
			if(!bj[i]){
				int mi=1e9;
				for(int j=1;j<=n;j++){
					if(i!=j)mi=min(mi,dis(i,j));
				}
				an=max(an,mi);
			}
		}
		ans=min(ans,an);
		return;
	}
	if(id==n+1)return;
	bj[id]=1;
	dfs1(id+1,num+1);
	bj[id]=0;
	dfs1(id+1,num);
}
void work(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs2(1,0);
	for(int i=1;i<=21;i++){
		for(int j=1;j<=n;j++){
			dp[j][i]=dp[dp[j][i-1]][i-1];
		}
	}
	dfs1(1,0);
	cout<<ans;
	for(int i=1;i<=21;i++){
		for(int j=1;j<=n;j++){
			dp[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	op();
	int c,T;
	cin>>c>>T;
	while(T--){
		work();
		cout<<"\n";
	}
}
