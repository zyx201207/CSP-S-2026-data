#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q,w[500005],k,xa,ya,l;
bool vis[500005];
ll ans;
vector<int>a[505],t[505];
struct node{int y,i,t;};
vector<node>g[500005];
void dfs(int x,int i,ll sum){
	if(l){
		int mn=0x3f3f3f3f;
		for(auto j:g[x])if(j.y==l)mn=min(mn,j.t);
		sum+=mn;
	}
	//cout<<x<<' '<<i<<' '<<sum<<' '<<ans<<'\n';
	if(x==ya){
		sum+=w[ya];
		ans=min(ans,sum);
		return;
	}
	for(auto j:g[x]){
		if(vis[j.y])continue;
		vis[j.y]=1;
		l=!i*x;
		dfs(j.y,j.i,sum+((i!=j.i&&i!=0)||j.y==ya)*j.t+(i?(i!=j.i)*t[i][x]:0));
		vis[j.y]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int aj,tj;
		for(int j=1;j<=k;j++){
			cin>>aj>>tj;
			a[i].push_back(aj);
			t[i].push_back(tj);
			if(j!=1){
				g[a[i][j-2]].push_back({aj,i,tj});
				g[aj].push_back({a[i][j-2],i,t[i][j-2]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xa>>ya;
		ans=0x3f3f3f3f3f3f3f3f;
		memset(vis,0,sizeof(vis));
		vis[xa]=1;
		dfs(xa,0,w[xa]);
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
