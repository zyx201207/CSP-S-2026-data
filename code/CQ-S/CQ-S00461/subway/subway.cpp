#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
constexpr int N=505,M=2e4+5;
int c,n,m,d,q,w[N],k[N];
ll minn=1e9+5;
vector<int> a[N],t[N],ps[M];
int ps2[M][N];
bitset<N> vis2;
inline void dfs(int x,int mb,ll js){
	if(x==mb){
		minn=min(minn,js);
		return;
	}
	for(const auto &ls:ps[x]){
		if(vis2[ls])continue;
		vis2[ls]=1;
		for(int i=1;i<=k[ls];++i){
			dfs(a[ls][i],mb,js+ps2[x][ls]+t[ls][i]);
		}
		vis2[ls]=0;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			ps[a[i][j]].emplace_back(i);
			ps2[a[i][j]][i]=t[i][j];
		}
	}
	while(q--){
		ll l,r;
		ll res=0;
		minn=1e9+5;
		cin>>l>>r;
		res+=w[l]+w[r];
		dfs(l,r,0);
		res+=minn;
		cout<<res<<"\n";
	}






	return 0;
}




