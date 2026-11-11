#include<bits/stdc++.h>
#define int long long
#define mpr make_pair
using namespace std;
const int N = 5e5+5;
const int M = 505;
int w[N],k[M],n,m,c,d,q,xy,z,x,y,xymx;
int min_n2=LLONG_MAX;
vector<int>st[N];
vector<int>un[M];
map<pair<int,int>,int>mp;
int vis[105],mnn;
void dfs(int step,int k,int s){
	if(step==k){
		mnn=min(mnn,s);
		return;
	}
	for(auto i:st[step]){
		for(auto j:un[i]){
			if(vis[j]<=s+mp[mpr(i,step)]+mp[mpr(i,j)])continue;
			int p=vis[j];
			vis[j]=s+mp[mpr(i,step)]+mp[mpr(i,j)];
			dfs(j,k,s+mp[mpr(i,step)]+mp[mpr(i,j)]);
//			vis[j]=p;
		}
	}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&xy,&z);
			st[xy].push_back(i);
			un[i].push_back(xy);
			mp[mpr(i,xy)]=z;
			if(n==2){
				if(mp.count(mpr(1,xy))&&mp.count(mpr(2,xy)))min_n2=min(min_n2,mp[mpr(1,xy)]+mp[mpr(2,xy)]);
			}
		}
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
		if(n==1){
			cout<<w[x]+w[y]+mp[mpr(1,x)]+mp[mpr(1,y)]<<'\n';
		}
		else if(n==2){
			int ans=LLONG_MAX;
			if((mp.count(mpr(1,x))&&mp.count(mpr(1,y))))ans=min(ans,w[x]+w[y]+mp[mpr(1,x)]+mp[mpr(1,y)]);
			if((mp.count(mpr(2,x))&&mp.count(mpr(2,y))))ans=min(ans,w[x]+w[y]+mp[mpr(2,x)]+mp[mpr(2,y)]);
			if(ans==LLONG_MAX){
				if(mp.count(mpr(1,x))){
					ans=w[x]+w[y]+mp[mpr(1,x)]+mp[mpr(2,y)]+min_n2;
				}
				else ans=w[x]+w[y]+mp[mpr(2,x)]+mp[mpr(1,y)]+min_n2;
			}
			cout<<ans<<'\n';
		}
		else if(c<=6){
			for(int i=1;i<=m;i++)vis[i]=LLONG_MAX;
			mnn=LLONG_MAX;
			dfs(x,y,0);
			cout<<mnn+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
