#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e1+5;
bool vis[N];
vector<int>tu[N];
int c,T,n,m,a[N],ans;
int dfs1(int x,int fa,int cnt){
	if(vis[x])
		return cnt;
	int t=LLONG_MAX;
	for(int i=0;i<tu[x].size();i++){
		int y=tu[x][i];
		if(y==fa)
			continue;
		t=min(t,dfs1(y,x,cnt+1));
	}
	return t;
}
void dfs2(int x,int fa){
	vis[x]=0;
	for(int i=0;i<tu[x].size();i++){
		int y=tu[x][i];
		if(y==fa||!vis[y])
			continue;
		dfs2(y,x);
	}
}
void dfs(int d,int cnt){
	if(cnt>m)
		return;
	if(d==n+1){
		if(cnt<m)
			return;
		int t=0,cnt=0;
		for(int i=1;i<=n;i++)
			t=max(t,dfs1(i,-1,0));
		if(t>=ans)
			return;
		bool vis1[N];
		for(int i=1;i<=n;i++)
			vis1[i]=vis[i];
		for(int i=1;i<=n;i++)
			if(vis[i]){
				dfs2(i,-1);
				cnt++;
			}
		for(int i=1;i<=n;i++)
			vis[i]=vis1[i];
		if(cnt<=2)
			ans=t;
		return;
	}
	dfs(d+1,cnt);
	vis[d]=1;
	dfs(d+1,cnt+1);
	vis[d]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=LLONG_MAX;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			tu[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			tu[x].push_back(y);
			tu[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
