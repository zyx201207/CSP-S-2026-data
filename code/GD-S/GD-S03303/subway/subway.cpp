#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[N],s[N];
ll ans;
vector<pair<int,int>>g[N];
vector<int>f[M];
bool b1[N],b2[M];//b1线路,b2站台

int ge(int li,int k){
	for(int i=1;i<=s[li];i++)
		if(g[li][i].first==k)
			return g[li][i].second;
	return 0;
}

void dfs(int k,int sum,int xl,int des){//k站,xl经过路线,des目的地 在k站中层处
	if(xl>n)return;
	if(k==des){
		ans=min(ans,1ll*sum+w[des]);
		return;
	}
	for(auto& li:f[k]){
		if(b1[li])continue;
		for(auto& u:g[li])
			if(!b2[u.first]){
				b1[li]=b2[u.first]=true;
				dfs(u.first,sum+ge(li,k)+u.second,xl+1,des);
				b1[li]=b2[u.first]=false;
			}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,a,t;i<=n;i++){
		cin>>s[i];
		g[i].resize(s[i]+1);
		for(int j=1;j<=s[i];j++){
			cin>>g[i][j].first>>g[i][j].second;
			f[g[i][j].first].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		b2[x]=true;
		dfs(x,w[x],0,y);
		cout<<ans<<'\n';
	}
	return 0;
}
