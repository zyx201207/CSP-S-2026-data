#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define l first
#define r second
using namespace std;
const int maxn=5e3+5,maxN=2e6+5;
int n,m,a[maxN],dis[maxn][maxn],ans,d;
vector<pii> q,tmp;
vector<int> num[maxn][maxn];
void bfs(int p){
	if(!q.size()) return;
	while(q.size()){
		int x=q[q.size()-1].l,y=q[q.size()-1].r;
		q.pop_back();
		for(int i=y+1;i<=n;i++){
			if(a[i]-a[y]<=m&&dis[x][i]>=p){
				tmp.push_back({x,i}),dis[x][i]=p;
				num[x][i].push_back(p);
				if(num[x][i].size()==2) ans++;
				if(num[x][i].size()==3) ans--;
			}
		}
	}
	while(tmp.size()) q.push_back({tmp[tmp.size()-1].l,tmp[tmp.size()-1].r}),tmp.pop_back();
	bfs(p+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C<=10){
			ans=0;
			tmp.clear(),q.clear();
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) num[i][j].clear();
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e5;
			for(int i=1;i<n;i++) q.push_back({i,i}),dis[i][i]=0;
			bfs(1);
			cout<<ans<<"\n";
		}
		else if(C<=12){
			d=m/(a[2]-a[1]);
			if(d==1||d==0) cout<<0<<"\n";
			else cout<<max(0ll,n-2*d+1)<<"\n";
		}
	}
	return 0;
}
