#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,T,n,dis[1000005],vis[1000005];
vector<int> G[1000005];
ll d,x[1000005],cnt[1000005],ans;
void solve(){ cin >> n >> d,ans=0;
	for(int i=1;i<=n;i++) 
		cin >> x[i],G[i].clear();
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		if(x[j]-x[i]<=d) G[i].push_back(j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cnt[j]=vis[j]=0,dis[j]=2e9;
		queue<int> Q; Q.push(i),cnt[i]=1,dis[i]=0;
		while(!Q.empty()){
			int x=Q.front(); Q.pop();
			if(!vis[x]){
				vis[x]=1;
				for(int to:G[x]) 
					if(dis[to]>dis[x]+1) Q.push(to),cnt[to]+=cnt[x],dis[to]=dis[x]+1;
					else if(dis[to]==dis[x]+1) cnt[to]+=cnt[x];
			}
		} for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
	} cout << ans << '\n';
} int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> C >> T; while(T--) solve(); return 0;
}
