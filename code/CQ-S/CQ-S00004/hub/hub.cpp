#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[100005],f[100005][21],dep[200005],minn=1e9;
bool vis[100005],vis2[100005],vis3[100005];
vector<int>vec[100005];
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=20;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
void dfs(int x){
	if(x==k+1){
		int sum=0;
		for(int i=1;i<=k;i++){
			if(!vis[f[a[i]][0]]){
				sum++;
			}
		}
		if(sum<=2){
			int maxn=0;
			for(int i=1;i<=k;i++){
				int minn2=1e9;
				for(int j=1;j<=k;j++){
					if(i==j){
						continue;
					}
					minn2=min(minn2,dis(i,j));
				}
				maxn=max(maxn,minn2);
			}
			minn=min(minn,maxn);
		}
		return;
	}
	for(int i=a[x-1]+1;i<=n;i++){
		a[x]=i;
		vis[i]=1;
		dfs(x+1);
		a[x]=0;
		vis[i]=0;
	}
}
void dfs2(int x,int fa){
	vis3[x]=1;
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i:vec[x]){
		if(vis3[i]){
			continue;
		}
		dfs2(i,x);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		minn=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			vis2[i]=vis3[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
			vis2[v]=1;
		}
		int rt=0;
		for(int i=1;i<=n;i++){
			if(!vis2[i]){
				rt=i;
				break;
			} 
		}
		dfs2(1,0);
		for(int j=1;j<=20;j++){
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
		}
		dfs(1);
		cout<<minn<<endl;
	}
	return 0;
}
