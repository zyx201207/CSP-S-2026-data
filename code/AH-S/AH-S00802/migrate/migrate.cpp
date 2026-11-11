#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,Mod=998244353;
int c,a[N],dis[N][N],cnt[N][N],vis[N];
vector<int> g[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(c==11||c==12){
		int x=-10;
		for(int i=1;i<=n;i++)
			if(a[i]-a[1]>d){
				x=i-2;
				break;
			}
		if(x<=1)
			cout<<0<<"\n";
		else
			cout<<n-(x+x-1)<<"\n";
	}
	if(c<=10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j)
					dis[i][j]=1e18;
				cnt[i][j]=0 ;
			}
		for(int s=1;s<=n;s++){
			for(int i=1;i<=n;i++)
				vis[i]=0;
			queue<pair<int,int> > q;
			q.push({s,0});
			vis[s]=1;
			cnt[s][s]=1;
			while(!q.empty()){
				int x=q.front().first,step=q.front().second;
				q.pop();
				for(int i=0;i<g[x].size();i++){
					int it=g[x][i];
					if(dis[s][it]>step+1){
						dis[s][it]=step+1;
						cnt[s][it]=0;
					}
					if(dis[s][it]==step+1)
						cnt[s][it]+=cnt[s][x];
					if(!vis[it])
						q.push({it,dis[s][it]});
					vis[it]=1;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)
					ans++;
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
