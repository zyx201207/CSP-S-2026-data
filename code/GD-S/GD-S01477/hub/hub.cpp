#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,T,n,k;
vector<int> G[11];
int dep[11],f[11][11],fa[11];
void dfs(int x,int xfa){
	dep[x]=dep[xfa]+1;
	fa[x]=xfa;
	for(int y:G[x])if(y!=xfa){
		dfs(y,x);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
int pc(int x){
	int cnt=0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
int ffa[11];
int find(int x){
	return ffa[x]=(ffa[x]==x?x:find(ffa[x]));
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			f[i][j]=dep[i]+dep[j]-dep[LCA(i,j)]*2;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
		}
		int ans=n-1;
		for(int s=0;s<(1<<n);s++)if(pc(s)==k){
			for(int i=1;i<=n;i++)ffa[i]=i;
			int cnt=k;
			for(int i=1;i<=n;i++)if((s>>i-1)&1){
				for(int j:G[i]){
					if(((s>>j-1)&1)&&find(i)!=find(j)){
						ffa[find(i)]=find(j);
						cnt--;
					}
				}
			}
//			cout<<s<<" "<<cnt<<'\n';
			if(cnt<=2){
//				cout<<"AC:"<<s<<'\n';
				int mx=0;
				for(int i=1;i<=n;i++){
					int mn=n-1;
					for(int j=1;j<=n;j++)if((s>>j-1)&1)mn=min(mn,f[i][j]);
					mx=max(mx,mn);
//					cout<<mn<<" \n"[i==n];
				}
				ans=min(ans,mx);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

