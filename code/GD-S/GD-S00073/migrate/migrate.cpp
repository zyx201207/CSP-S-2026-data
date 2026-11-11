#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
int c,T,n,to[N],sz[N],s[N][2];//s[x][0]->满足的点，s[x][1]->被淘汰的点 
bool is[N],vis[N];
ll d,ans,a[N];
vector<int> G[N];
void dfs(int x){
	vis[x]=true;
	sz[x]=s[x][0]=s[x][1]=0;
	for(auto y:G[x]){
		if(!vis[y]) dfs(y);
		sz[x]+=sz[y]+1;
		if(is[y]){//原先满足的不再满足
			for(auto z:G[y]){
				if(to[z-1]>=y-1||is[z]){
					s[x][0]++;
					s[x][1]+=sz[z];
				}else{
					s[x][0]+=sz[z]+1-s[z][0]-s[z][1];
					s[x][1]+=s[z][0]+s[z][1];
				}
			}
		}else{
			s[x][0]+=s[y][0];
			s[x][1]+=s[y][1];
		}
	}
	ans+=s[x][0];
//	printf("%d->%d %d %d\n",x,sz[x],s[x][0],s[x][1]);
}
void solve(){
	scanf("%d%lld",&n,&d);
	ans=0;
	for(int i=1;i<=n;i++){
		G[i].clear();
		is[i]=vis[i]=false;
		to[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
//	printf("d:%lld\na:",d);
//	for(int i=1;i<=n;i++){
//		printf("%lld ",a[i]);
//	}
//	printf("\n");
	for(int i=1,j=1;i<=n;i++){
		j=max(j,i);
		while(j<n&&a[j+1]-a[i]<=d) j++;
		to[i]=j;
	}
	for(int i=1;i<=n;i++){
		if(i!=to[i]) G[to[i]].push_back(i);
		if(to[i]>i+1&&to[to[i]]!=to[i]&&to[to[i]-1]==to[to[i]]&&(to[i]-2==i||to[to[i]-2]!=to[to[i]])) is[to[i]]=true;
	}
//	printf("is:");
//	for(int i=1;i<=n;i++){
//		if(is[i]) printf("%d ",i);
//	}
//	printf("\n");
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
//	printf("pre:");
//	for(int i=1;i<=n;i++){
//		printf("%lld ",pre[i]);
//	}
//	printf("\n");
//	printf("::%lld\n",ans);
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&to[j]<=i) j++;
		if(i==j) continue;
		ll t=0;
		if(G[i].empty()){
			t+=s[j][0];
			if(j+1<i){
				for(auto z:G[j+1]){
					if(to[z-1]>=j+1-1||is[z]){
						t++;
					}else{
						t+=sz[z]+1-s[z][0]-s[z][1];
					}
				}
			} 
		}else{
			for(auto z:G[j]){
				if(to[z-1]>=j-1||is[z]){
					t++;
				}else{
					t+=sz[z]+1-s[z][0]-s[z][1];
				}
			}
		}
		ans+=t;
//		if(t) printf("%d->%d %lld\n",i,j,t);
	}
	printf("%lld\n",ans);
}
int main(){
//	system("fc migrate.out migrate6.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
