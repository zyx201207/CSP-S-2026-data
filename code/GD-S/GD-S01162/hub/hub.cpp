#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5005
int c,t;
vector <int> edge[N];
int a[N];
int fa[N];
void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	return fa[x]==x ? x : find(fa[x]);
} 
void merge(int x,int y){
	if(x>y) swap(x,y);
	if(find(x)==find(y)) return;
	fa[find(x)]=fa[find(y)];
}
bool vis[N];
int dis[N];
bool vvis[N];
bool vvis_j[N];
void djs(int start,int n){
	for(int i=1;i<=n;i++){
		dis[i]=1e12+111;
		vvis[i]=false;
		vvis_j[i]=false;
	}
	vvis[start]=true;
	dis[start]=0;
	for(int i=1;i<=n;i++){
		int j=-1,mn=1e12;
		for(int k=1;k<=n;k++){
			if(vvis_j[k]) continue;
			if(dis[k]<mn){
				mn=dis[k];
				j=k;
			}
		}
		//cout<<j<<" "<<mn<<"\n";
		if(j==-1) return;
		vvis_j[j]=true;
		for(auto v : edge[j]){
			if(vvis[v]||find(j)!=find(v)) continue;
			vvis[v]==true;
			dis[v]=min(dis[v],dis[j]+1);
			//cout<<"   "<<v<<" "<<dis[v]<<"\n";
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int mn=1;
		for(int jj=1;jj<=1<<k;jj++){
			int j=jj;
			a[1]=log2(j&(-j));
			a[1]-=t<<2;
			for(int g=2;g<=k;g++){
				a[g]=log2(j&(-j));
				j-=a[g]<<2;
				merge(a[g],a[g-1]);
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				cnt+=!(vis[find(i)]);
				vis[find(i)]=true;
			}
			for(int i=1;i<=n;i++) vis[i]=false,a[i]=0;
			if(cnt!=2) continue;
			int mx=-1e12+111;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					djs(i,n);
					if(dis[j]<1e10) mx=max(mx,dis[j]);
				}
			}
			mn=min(mx,mn);
		}
		cout<<mn<<"\n";
		for(int i=1;i<=n;i++) edge[i].clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 



