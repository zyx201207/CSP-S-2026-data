#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[505][20005];
int t[505][20005];
int k[maxn];
int w[maxn];
int dis[maxn];
int vis[maxn];
int tftf[maxn];
int c,n,m,d,q;
int ans=0;
int x,y;
int nowline;
void dfs(int now){
	if(now==y){
		ans=min(ans,dis[now]+t[nowline][now]);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i]/2;j++){
			if(a[i][j]==now){
				if(!vis[a[i][j-1]]&&(j-1)>0){
					vis[a[i][j-1]]=1;
					if(i==nowline)dis[a[i][j-1]]=dis[now];
					else{
						dis[a[i][j-1]]=min(dis[a[i][j-1]],dis[now]+t[nowline][j]+t[i][j]);
						nowline=i;
					}
					dfs(a[i][j-1]);
					vis[a[i][j-1]]=0;
				}
				if(!vis[a[i][j+1]]&&(j+1)<=k[i]){
					vis[a[i][j+1]]=1;
					if(i==nowline)dis[a[i][j+1]]=dis[now];
					else{
						dis[a[i][j+1]]=min(dis[a[i][j+1]],dis[now]+t[nowline][j]+t[i][j]);
					}
					nowline=i;
					dfs(a[i][j+1]);
					vis[a[i][j+1]]=0;
				}
			}
		}
	}
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			tftf[j]++;
		}
	}
	while(q--){
		ans=5e18+10;
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		cin>>x>>y;
		dis[x]=0;
		vis[x]=1;
		dfs(x);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
