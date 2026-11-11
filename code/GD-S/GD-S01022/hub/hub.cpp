#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],c,t,k,fa[N],f[20][20],vis[N];
vector<int> e[N];
void init(){
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
}
void init2(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		vis[i]=0;
	}
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y),fa[x]=y;
}
void solve(){
	scanf("%d %d",&n,&k);
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=n;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		f[u][v]=f[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	int ans=n;
	for(int i=0;i<(1<<n);i++){
		init2();
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				cnt++;
				vis[j]=1;
				for(int k=0;k<e[j].size();k++){
					if(vis[e[j][k]]){
						merge(e[j][k],j);
					}
				}
			}
		}
		if(cnt!=k)continue;
		cnt=0;
		for(int j=1;j<=n;j++){
			if(find(j)==j)cnt++;
		}
		if(cnt>2)continue;
		int maxn=0;
		for(int j=1;j<=n;j++){
			int minn=n;
			if(((i>>(j-1))&1)==0)continue;
			for(int k=1;k<=n;k++){
				if(((i>>(k-1))&1)==0)continue;
				minn=min(f[j][k],minn);
			}
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}/*

*/
