#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
typedef std::pair<int,int> pii;
using namespace std;
int c,n,m,d,q,w[500005],x[500005],y[500005],dis[505][505];
vector<pii>e[500005];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	fre("subway");
	cin>>c>>m>>n>>d>>q;
	rep(i,1,n) cin>>w[i];
	memset(dis,0x3f,sizeof dis);//ÏßÂ·¾àÀë
	rep(i,1,m) dis[i][i]=0;
	rep(i,1,m){
		int k;cin>>k;
		rep(j,1,k) cin>>x[j]>>y[j],e[x[j]].push_back({i,y[j]});
	}
	rep(i,1,n) for(auto [j,w1]:e[i]) for(auto [k,w2]:e[i])
		dis[j][k]=min(dis[j][k],w1+w2);
	rep(k,1,m) rep(i,1,m) rep(j,1,m) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	//O(md^2+n^3) 
	while(q--){
		int x,y,ans=1e18;cin>>x>>y;
		if(x==y){cout<<"0\n";continue;}
		for(auto [j,w1]:e[x]) for(auto [k,w2]:e[y])
			ans=min(ans,w[x]+w[y]+w1+w2+dis[j][k]);
		cout<<ans<<"\n";
	}
}

