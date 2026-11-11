#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,dis[N],vis[N];
vector<int> e[N];
void dfs1(int x,int fa){
	for(int y:e[x]){
		if(y==fa) continue;
		dis[y]=min(dis[y],dis[x]+1);
		dfs1(y,x);
	}
}
void dfs2(int x,int fa){
	vis[x]=1;
	for(int y:e[x]){
		if(y==fa || dis[y]!=0) continue;
		dfs2(y,x);
	}
}
void task1(){
	int ans=0x3f3f3f3f;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		for(int j=1;j<=n;j++){
			if(i>>(j-1)&1){
				dis[j]=0;
				dfs1(j,j);
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i>>(j-1)&1 && vis[j]==0){
				cnt++;
				dfs2(j,j);
			}
		}
		if(cnt>2) continue;
		int res=0;
		for(int j=1;j<=n;j++) res=max(res,dis[j]);
		ans=min(ans,res); 
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
//	freopen("hub4.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(n<=10 && k<=10){task1();continue;}
//		if(n<=1000){task2();continue;}
	}
	return 0;
}

