#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+10;
const int maxn=510;
int c,n,m,dd,q;
int w[maxm],k[maxn];
map<int,map<int,int>> bk;
map<int,map<int,int>> ans;
vector<int> a[maxn],t[maxn];
int solve(int l,int r){
	if(l==r)return 0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	map<int,map<int,int>>d;
	map<int,map<int,bool>> vis;
	for(int i=1;i<=n;i++){
		if(bk[i][l]){
			d[l][i]=t[i][bk[i][l]];
			q.push({d[l][i],{l,i}});
		}
	}
	while(!q.empty()){
		int w=q.top().first;
		int u=q.top().second.first;
		int nn=q.top().second.second;
		q.pop();
		if(d[u][nn]!=w)continue;
		if(vis[u][nn])continue;
		vis[u][nn]=1;
		if(bk[nn][u]<k[nn]){
			if((!d[a[nn][bk[nn][u]+1]][nn])||d[a[nn][bk[nn][u]+1]][nn]>d[u][nn]){
				d[a[nn][bk[nn][u]+1]][nn]=d[u][nn];
				if(!vis[a[nn][bk[nn][u]+1]][nn])q.push({d[a[nn][bk[nn][u]+1]][nn],{a[nn][bk[nn][u]+1],nn}});
			}
		}
		int sum=t[nn][bk[nn][u]];
		for(int i=1;i<=n;i++){
			if(bk[i][u]){
				if((!d[u][i])||d[u][i]>d[u][nn]+sum+t[i][bk[i][u]]){
					d[u][i]=d[u][nn]+sum+t[i][bk[i][u]];
					if(!vis[u][i])q.push({d[u][i],{u,i}});
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(bk[i][r]&&d[r][i]){
			int w=d[r][i]+t[i][bk[i][r]];
			if(!ans)ans=w;
			else ans=min(ans,w);
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			bk[i][a[i][j]]=j;
		}
	} 
	while(q--){
		int l,r;
		cin>>l>>r;
		if(!ans[l][r])ans[l][r]=w[l]+w[r]+solve(l,r);
		cout<<ans[l][r]<<'\n';
	}
	return 0;
}
