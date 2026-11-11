#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define xt first
#define yt second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
constexpr int N=5005;
ll c,t,n,d,a[N];
vector<pair<ll,pair<ll,ll>>> ps[N];
vector<pair<ll,ll>> ps2[N];
inline void dfs(ll x,ll js){
	for(int ks=x+1;ks<=n;++ks){
		if(abs(a[x]-a[ks])<=d){
			if(ps[x][ks].xt==0)ps[x][ks]={1,{js,ks}};
			else{
				if(ps[x][ks].yt.xt>js){
					ps[x][ks]={1,{js,ks}};
				}else if(ps[x][ks].yt.xt==js){
					ps[x][ks].xt++;
				}
			}
			dfs(ks,js+1);
			for(const auto &k:ps[ks]){
				if(ps[x][k.yt.yt].xt==0||ps[x][k.yt.yt].yt.xt>k.yt.xt){
					ps[x][k.yt.yt]={1,{k.yt.xt,k.yt.yt}};
				}else if(ps[x][k.yt.yt].yt.xt==k.yt.xt){
					ps[x][k.yt.yt].xt++;
				}
			}
		}
	}
	return ;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i],ps[i].clear(),ps[i].resize(n+5);
	ll res=0;
	for(int i=1;i<=n;++i)dfs(i,1);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(ps[i][j].xt==2)++res;
		}
	}
	cout<<res<<"\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)solve(); 








	return 0;
}




