#include<bits/stdc++.h>
#define int long long 
using namespace std;
int now,T,n,m,a[2000010],s[2000010],can[2000010],pos[2000010],dis[2000010],f[2000010][22],ans,tot,vis[2000010],cannot[2000010];
vector<int> vec[2000010];
void solve(int x,int dist){
	dis[x]=dist;vis[x]=tot;
	for(int i=0;i<vec[x].size();i++){
		solve(vec[x][i],dist+1); 
	}
}
void RMQ(){
	for(int i=1;i<=n;i++)f[i][0]=can[i];
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
int LCA(int x,int y){
	if(dis[x]<dis[y])swap(x,y);
	for(int i=log2(dis[x]-dis[y]);i>=0;i--){
		if(dis[x]-dis[y]>=(1<<i))x=f[x][i];
	}
	if(x==y)return x;
	for(int i=log2(dis[x]);i>=0;i--){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> now >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			vec[i].clear();
		}
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]>m||i==n)can[i]=i;
			else{
				if(a[n]-a[i]<=m){
					vec[n].push_back(i);
					can[i]=n;
				}
				else{
					can[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
					vec[can[i]].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]>m||i==1)cannot[i]=i;
			else{
				if(a[i]-a[1]<=m){
					cannot[i]=1;
				}
				else{
					cannot[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
				}
			}
		}
		tot=0;
		for(int i=1;i<=n;i++){
			if(can[i]==i)tot++,solve(i,0);
		}
		for(int i=1;i<=n;i++){
			if(cannot[i]==i){
				s[i]=0;
			}else{
				s[i]=s[cannot[i]]+1;
			}
		}
		RMQ();ans=0;
		for(int i=1;i<=n;i++){
			if(can[i]==i)continue;
			if(can[i]-1<=i||(i!=1&&can[i]-2>i&&vis[can[i]-2]==vis[can[i]]&&dis[can[i]-2]==dis[can[i]]))continue;
			if(vis[can[i]-1]!=vis[can[i]])continue;
			int lca=LCA(can[i]-1,can[i]);
			ans+=dis[can[i]-1]-dis[lca]-1;
			if(dis[can[i]-1]==dis[can[i]])ans+=dis[lca]+1+s[i];
		}
		cout << ans << endl;
	}
	return 0;
}
