#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5; 
int c,n,d,m,e1,q,w[N],js[N],tot;
ll fl[505][505];
vector<int>a[N],t[N];
unordered_map<int,ll>G[N];
vector<int>hv[N];
vector<int>nz[N];
pii read(){
	int x,y;
	cin>>x>>y;
	return {x,y};
}
void solve1(){
	for(int i=1;i<=n;i++){
		int k=js[i];
		for(int j=1;j<=k;j++){
			int x=a[i][j-1],y=t[i][j-1];
			G[i][x]=y;
			hv[i].push_back(x);
			nz[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k:hv[j]){
				if(!G[i].count(k))continue;
				fl[i][j]=min(fl[i][j],G[i][k]+G[j][k]);
			}
		}
	}
	for(int i=1;i<=tot;i++)fl[i][i]=0;
	for(int k=1;k<=tot;k++){
		for(int x=1;x<=tot;x++){
			for(int y=1;y<=tot;y++){
				if(fl[x][k]>3e18||fl[k][y]>3e18)continue;
				fl[x][y]=min(fl[x][y],fl[x][k]+fl[k][y]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=LLONG_MAX;
		for(int i:nz[u]){
			for(int j:nz[v]){
				ans=min(ans,G[i][u]+G[j][v]+fl[i][j]);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(fl,0x3f,sizeof fl);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	tot=n;
	int s=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		s+=k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x;
			a[i].push_back(x);
			cin>>y;
			t[i].push_back(y);
		}
		js[i]=k;
	}
	if(s<=7e18)solve1();
} 
