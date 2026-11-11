#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+5;

int n,m;
int a[N],in[N],inn[N],dis[N],cnt[N];
vector<int> e[N];
queue<int> r;

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=m){
				e[i].push_back(j);
				in[j]++;
			}
		}
		for(int j=i+1;j<=n;j++){
			in[j]+=inn[j],inn[j]=in[j];
			dis[j]=2e18;
			cnt[j]=0;
		}
		cnt[i]=1;
		dis[i]=0;
		while(r.size()) r.pop();
		r.push(i);
		while(!r.empty()){
			int u=r.front();
			r.pop();
			//cout<<u<<" ";
			for(auto v:e[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					cnt[v]=cnt[u];
				}
				else if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
				if(!--in[v]) r.push(v);
			}
		}
	//	cout<<"\n";
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) in[i]=inn[i]=0,e[i].clear();
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

