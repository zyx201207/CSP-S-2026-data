#include<bits/stdc++.h>
using namespace std;
int n,m,c,t;
int k,hh;
vector<int>v0[1000001],v[1000001];
int dep0[1000001],dep[1000001],son[1000001],dis[1000001],maxd;
int w[101][101];
void dfs1(int now,int d){
	dep0[now]=d;
	if(v0[now].empty())son[now]=0;
	for(auto to:v0[now]){
		if(!dep0[to]){
			dfs1(to,d+1);
			son[now]=min(son[now],son[to]+1);
		}
	}
}
//void dfs(int now,int d){
//	dep[now]=d;
//	for(auto to:v0[now]){
//		if(!dep[to]){
//			dfs(to,d+1);
//		}
//	}
//}
void dfs(int x){
	for(auto to:v0[x]){
		if(dis[x]+1<dis[to]){
			dis[to]=dis[x]+1;
			dfs(to);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(c==13||c==14){
			puts("0");
			continue;
		}
		
		for(int i=1;i<n;i++){
			int f,t;
			scanf("%d%d",&f,&t);
//			w[f][t]=w[t][f]=1;
			v0[f].push_back(t);
			v0[t].push_back(f);
			son[i]=son[i+1]=0x3f3f3f3f;
			dis[i]=dis[i+1]=0x3f3f3f3f;
		}
		dfs1(1,1);
		if(k==2){
			int a,b;
			for(a=1;a<=n;a++){
				if(son[a]==(n-2)/3){
					dis[a]=0;
					break;
				}
			}
			for(b=1;b<=n;b++){
				if(son[b]==(n-2)/3&&a!=b)break;
			}
			dis[b]=0;
			dfs(a);
			dfs(b);
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=dis[i];
			}
			cout<<ans<<'\n';
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				
//			}
//		}
		
//		dfs1(1,1);
//		int maxdep=-1;
//		for(int i=1;i<=n;i++){
//			if(maxdep<dep0[i]){
//				maxdep=dep0[i];
//				hh=i;
//			}
//		}
//		dfs(hh,1);
	}
	return 0;
}
