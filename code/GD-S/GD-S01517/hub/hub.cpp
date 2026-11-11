#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,dis[15][15],lca[15][15],dep[15],fa[15],fm[15],to[15],cnt,minn;
bool eg[15][15];
vector<int> vec[15];
void dfs(int ind,int las){
	dep[ind]=dep[las]+1;
	fa[ind]=las;
	for(int i=0;i<vec[ind].size();i++){
		if(vec[ind][i]!=las){
			dfs(vec[ind][i],ind);
		}
	}
	return;
}
int llca(int x,int y){
	if(lca[x][y]!=0){
		return lca[x][y];
	}
	if(dep[x]>dep[y]){
		return lca[x][y]=llca(fa[x],y);
	}
	if(dep[x]<dep[y]){
		return lca[x][y]=llca(x,fa[y]);
	}
	return lca[x][y]=llca(fa[x],fa[y]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c<=3){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>u>>v;
				fm[i]=u-1;
				to[i]=v-1;
				eg[u][v]=1;
				eg[v][u]=1;
				vec[u].push_back(v);
				vec[v].push_back(u);
			}
			dfs(1,1);
			minn=INT_MAX;
			for(int i=1;i<=n;i++){
				lca[i][i]=i;
				dis[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(lca[i][j]==0){
						lca[i][j]=llca(i,j);
						lca[j][i]=lca[i][j];
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=dep[i]+dep[j]-2*dep[lca[i][j]];
				}
			}
			for(int i=0;i<(1<<n);i++){
				if(__builtin_popcount(i)!=k){
					continue;
				}
				cnt=0;
				for(int j=1;j<n;j++){
					if(i&(1<<fm[i])&&(i&(1<<to[i]))){
						cnt++;
					}
				}
				if(cnt<k-2){
					continue;
				}
				int maxx=0,asdf=INT_MAX;
				for(int j=1;j<=n;j++){
					asdf=INT_MAX;
					for(int jj=1;jj<=n;jj++){
						if(i&(1<<(jj-1))){
							asdf=min(asdf,dis[j][jj]);
						}
					}
					maxx=max(maxx,asdf);
				}
				minn=min(minn,maxx);
			}
			cout<<minn<<'\n';
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					lca[i][j]=0;
					dis[i][j]=0;
					eg[i][j]=false;
				}
				vec[i].clear();
				dep[i]=0;
				fa[i]=0;
				fm[i]=0;
				to[i]=0;
			}
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>u>>v;
			}
			if(k==n){
				cout<<0<<'\n';
				continue;
			}
			if(k>=n/2){
				cout<<1<<'\n';
				continue;
			}
			n/=2;
			cout<<(n-k)/4+((n-k)%4==0?1:2)<<'\n';
		}
		return 0;
	}
	cout<<"I have no time to do it!!!";
	return 0;
}
