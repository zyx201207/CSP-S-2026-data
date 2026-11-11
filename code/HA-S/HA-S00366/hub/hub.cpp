#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll x;cin>>x;return x;}
const int N=15;
int n,k,ans,num,cnt,vis[N],dis[N][N];
vector<int>Link[N]; 
int pop_count(int x){
	int o=0;
	while(x){
		o+=x%2;
		x/=2;
	}
	return o;
}
void dfs1(int x,int fa){
	for(auto y:Link[x]){
		if(y==fa||!vis[y]) continue;
		dfs1(y,x);
	}
	vis[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);cout.tie(0);
	for(int c=read(),T=read();T;T--){
		for(int i=1;i<=n;i++) Link[i].clear();
		n=read(),k=read();
		ans=1e9;
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			Link[x].push_back(y);
			Link[y].push_back(x); 
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=1e9;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int x=1;x<=n;x++)
			for(auto y:Link[x])
				dis[x][y]=dis[y][x]=1;
		for(int i=1;i<=n;i++)
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++)
					dis[x][y]=dis[y][x]=min(dis[x][y],dis[x][i]+dis[y][i]);
		for(int i=1;i<(1<<n);i++){
			if(pop_count(i)!=k) continue;
			num=cnt=0;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++)
				if(i&(1<<j-1)) vis[j]=1;
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1)&&vis[j]){
					cnt++;
					dfs1(j,0);
				}
			}
			if(cnt>2) continue;
			for(int x=1;x<=n;x++){
				int pos=1e9;
				if(i&(1<<x-1)) continue;
				for(int y=1;y<=n;y++){
					if(i&(1<<y-1)){
						pos=min(pos,dis[x][y]);
					}
				}
				num=max(num,pos);
			}
			ans=min(ans,num);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
