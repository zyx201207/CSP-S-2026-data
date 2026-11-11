#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7,M=607;
int csd;
int t,n;
long long a[N],d,ans;
int dis[N],vis[N],dc[N];
int f[M][M],fc[M][M];
bool check(){
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) return false;
	return true;
}
void dijkstra(int s){
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f,sizeof dis);for(int i=1;i<=n;i++) vis[i]=dc[i]=0;
	dis[s]=0;q.push({dis[s],s});dc[s]=1;
	while(q.size()){
		int now=q.top().second;q.pop();
		if(vis[now]) continue;vis[now]=1;
		for(int i=now+1;a[i]-a[now]<=d;i++){
			if(dis[now]+1==dis[i]){
				dc[i]+=dc[now];
			}
			else if(dis[now]+1<dis[i]){
				dis[i]=dis[now]+1;
				dc[i]=dc[now];
				q.push({-dis[i],i});
			}	
		}
	}
}
void solve(){
	cin>>n>>d;for(int i=1;i<=n;i++) cin>>a[i];
	if((long long)n*n*n<=200000000){
		memset(f,0x3f,sizeof f);memset(fc,0,sizeof fc);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]>d) continue;
				else f[i][j]=f[j][i]=fc[i][j]=fc[j][i]=1;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(f[i][k]+f[k][j]==f[i][j])
						fc[i][j]+=fc[i][k]*fc[k][j];
					else if(f[i][k]+f[k][j]<f[i][j])
						f[i][j]=f[i][k]+f[k][j],fc[i][j]=fc[i][k]*fc[k][j];
				}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(fc[i][j]==2) ans++;
	}else if(check()){
		for(int i=n;i>=2;i--)
			if((a[i]-a[1])-d>0&&(a[i]-a[1])-d<d&&(i-1)&1){
				ans=(n-i+1);
				break;
			}
	}else{
		for(int i=1;i<=n;i++){
			dijkstra(i);for(int j=1;j<=n;j++) if(dc[j]==2) ans++;
		}
	}cout<<ans<<'\n';ans=0;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>csd>>t;while(t--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
