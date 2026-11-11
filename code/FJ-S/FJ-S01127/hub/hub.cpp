#include <bits/stdc++.h>
#define zls rp++
#define ll long long
#define ull unsigned long long
using namespace std;
const int inf=2e9;
int n,k,d[1000005],l,r,dp[2][3][1000005];
int mx[1000005];
vector<int>e[1000005];
void dfs(int x,int fa){
	d[x]=d[fa]+1;
	mx[x]=d[x];
	sz[x]=1;
	r=max(r,d[x]-1);
	for(int v:e[x]){
		if(v==fa)continue;
		dfs(v,x);
		sz[x]+=sz[v];
		mx[x]=max(mx[x],mx[v]);
	}
}
int cnt=0;
void DP(int x,int fa,int dis){
	if(mx[x]-d[x]==dis){
		dp[1][1][x]=1;
		cnt++;
		return ;
	}
	for(int v:e[x]){
		if(v==fa)continue;
		DP(v,x,dis);
	}
}
bool check(int dis){
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int ok=0;ok<=1;ok++)for(int num=0;num<=2;num++)
			dp[ok][num][i]=inf;
	DP(1,0,dis);
}
void work(){
	cin>>n>>k;d[0]=0;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	l=r=0;
	dfs(1,0);
	if(k==n){
		cout<<"0\n";
		return ;
	}
	else{
		cout<<mx[1]/2<<"\n";
		return ;
	}
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)work();
	return 0;
}
