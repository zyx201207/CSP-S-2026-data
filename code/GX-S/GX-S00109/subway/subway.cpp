#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,d,p,c,ans;
ll w[500005];
ll k[505];
vector<vector<ll> >t(505);
map<ll,map<ll,ll> >tt;
ll x[100005];
ll y[100005];
ll ds[500005][30];
bool v[500005][30];
bool vv[500005];
void dfs(ll s,ll r,ll val,ll e,ll o){
	if(s==e){
		ans=min(ans,val+tt[r][s]);
		return;
	}
	if(r==0){
		for(int i=1;i<=ds[s][0];i++){
			ll z=ds[s][i];
			v[z][s]=1;
			dfs(s,z,val+tt[z][s],e,0);
			v[z][s]=0;
		}
	}else{
		for(ll i=0;i<k[r];i++){
			ll z=t[r][i];
			if(z!=s&&!vv[z]){
				vv[z]=1;
				dfs(z,r,val,e,1);
				vv[z]=0;
			}
		}
		if(o){
			for(int i=1;i<=ds[s][0];i++){
				ll z=ds[s][i];
				if(z!=r&&!v[s][i]){
					v[z][s]=1;
					dfs(s,z,val+tt[z][s]+tt[r][s],e,0);
					v[z][s]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll ppp,pppp;
			cin>>pppp>>ppp;
			t[i].push_back(pppp);
			tt[i][pppp]=ppp;
			ds[pppp][++ds[pppp][0]]=i;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=p;i++){
		memset(v,0,sizeof(v));
		memset(vv,0,sizeof(vv));
		vv[x[i]]=1;
		ans=1e18;
		dfs(x[i],0,0,y[i],1);
		ans+=w[x[i]]+w[y[i]];
		cout<<ans<<'\n';
	}
	return 0;
}
