#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int head[N],nxt[N],d[N],bx,T,k,state,siz[N],ans,dep[N],mmax,dis,c,n;
bool vis[N];
vector<int> mask;
void addedge(int u,int v){
	d[++bx]=v;
	nxt[bx]=head[u];
	head[u]=bx;
}
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=d[i];
		if(vis[v]||((state&(1<<v-1))==0)) continue;
		dfs(v);
	}
}
void dfs2(int u,int fa){
	if(fa!=0) dep[u]=dep[fa]+1;
	if(state&(1<<u-1)){
		dis=min(dis,dep[u]);
		return;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=d[i];
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>k;
		bx=0;
		mask.clear();
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			addedge(u,v);
			addedge(v,u);
		}
		int lim=1<<n;
		ans=1e7;
		for(int st=1;st<lim;st++){
			if(__builtin_popcount(st)!=k) continue;
			mask.push_back(st);
		}
		for(int i=0;i<mask.size();i++){
			state=mask[i];
			int cnt=0;
			siz[0]=0;
			for(int j=1;j<=n;j++) vis[i]=0;
			for(int j=1;j<=n;j++){
				if((state&(1<<(j-1)))==0) continue;
				if(!vis[j]){
					cout<<1;
					dfs(j);
					cnt++;
				}
			}
			if(cnt>2) continue;
			mmax=0;
			for(int j=1;j<=n;j++){
				if((state&(1<<(j-1)))==0){
					dis=1e7;
					for(int l=1;l<=n;l++) dep[l]=1e7;
					dep[j]=0;
					dfs2(j,0);
					mmax=max(mmax,dis);
				}
			}
			ans=min(ans,mmax);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

