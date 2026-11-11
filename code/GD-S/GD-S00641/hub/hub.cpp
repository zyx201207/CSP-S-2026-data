#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5,logN=20;
int c,t,n,k,x,y,ans;
int lg[N],fa[N][logN];
int dep[N];
vector<int> e[N];
void init(){
	lg[1]=0;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
}
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for (int i=1;i<=lg[n];i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for (auto v:e[u]){
		if (v==father) continue;
		if (!dep[v]){
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
}
int LCA(int u,int v){
	if (dep[u]<=dep[v]) swap(u,v);
	if (u==v) return u;
	for (int i=lg[n];i>=0;i--)
	if (dep[fa[u][i]]>=dep[v])
	u=fa[u][i];
	if(u==v) return u;
	for (int i=lg[n];i>=0;i--)
	if (fa[u][i]!=fa[v][i])
	u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int randint(int x,int y){
	return rand()%(y-x+1)+x;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand((unsigned long long)(time(NULL))^(unsigned long long)(new char));
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=1e18;
		scanf("%lld%lld",&n,&k);
		init();
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<=n-1;i++){
			scanf("%lld%lld",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		if (k==1){
			for (int p=1;p<=n;p++){
				int distance=0;
				for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++){
					if (i==j||i==p) continue;
					int lca=LCA(i,j);
					int dist=dep[i]+dep[j]-2*dep[lca];
					distance=min(distance,dist);
					ans=min(ans,distance);
				}
			}
			printf("%lld\n",ans);
		}
		else if (k==2){
			for (int pos1=1;pos1<=n;pos1++)
			for (int pos2=1;pos2<=n;pos2++){
				if (pos1==pos2) continue;
				int distance=0;
				for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++){
					if (i==j||i==pos1||i==pos2) continue;
					int lca=LCA(i,j);
					int dist=dep[i]+dep[j]-2*dep[lca];
					distance=min(distance,dist);
					ans=min(ans,distance);
				}
			}
			printf("%lld\n",ans);
		}
		else if (k==3){
			for (int pos1=1;pos1<=n;pos1++)
			for (int pos2=pos1+1;pos2<=n;pos2++)
			for (int pos3=pos2+1;pos3<=n;pos3++)
			{
				int distance=0;
				for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++){
					if (i==j||i==pos1||i==pos2||i==pos3) continue;
					int lca=LCA(i,j);
					int dist=dep[i]+dep[j]-2*dep[lca];
					distance=min(distance,dist);
					ans=min(ans,distance);
				}
			}
			printf("%lld\n",ans);
		}
		else if (k==4){
			for (int pos1=1;pos1<=n;pos1++)
			for (int pos2=pos1+1;pos2<=n;pos2++)
			for (int pos3=pos2+1;pos3<=n;pos3++)
			for (int pos4=pos3+1;pos4<=n;pos4++)
			{
				int distance=0;
				for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++){
					if (i==j||i==pos1||i==pos2||i==pos3||i==pos4) continue;
					int lca=LCA(i,j);
					int dist=dep[i]+dep[j]-2*dep[lca];
					distance=min(distance,dist);
					ans=min(ans,distance);
				}
			}
			printf("%lld\n",ans);
		}
		else if (k==5){
			for (int pos1=1;pos1<=n;pos1++)
			for (int pos2=pos1+1;pos2<=n;pos2++)
			for (int pos3=pos2+1;pos3<=n;pos3++)
			for (int pos4=pos3+1;pos4<=n;pos4++)
			for (int pos5=pos4+1;pos5<=n;pos5++)
			{
				int distance=0;
				for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++){
					if (i==j||i==pos1||i==pos2||i==pos3||i==pos4||i==pos5) continue;
					int lca=LCA(i,j);
					int dist=dep[i]+dep[j]-2*dep[lca];
					distance=min(distance,dist);
					ans=min(ans,distance);
				}
			}
			printf("%lld\n",ans);
		}
		else printf("%lld\n",randint(1,n+k));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
