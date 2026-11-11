#include<bits/stdc++.h>
using namespace std;
const int N=105;
#define ll long long
ll a,b,c,n,m,sum,ans=INT_MAX,tot,T,tot1[N],tot2[N],bj[N],lj[N][N],res,k,u,v;
vector<ll> ma[N];
ll check(){
	for(ll i=1;i<=n;i++)tot1[i]=tot2[i]=0;
	ll hed1=0,hed2=0;
	for(ll i=1;i<=n;i++){
		if(bj[i]){
			if(hed1==0){
				tot1[++hed1]=i;continue;
			}
			for(ll j=1;j<=hed1;j++){
				if(lj[i][tot1[j]]){
					tot1[++hed1]=i;
				}
			}
			if(hed2==0){
				tot2[++hed2]=i;continue;
			}
			for(ll j=1;j<=hed2;j++){
				if(lj[i][tot1[j]]){
					tot2[++hed2]=i;
				}
			}
		}
		if(tot2[hed2]!=i&&tot1[hed1]!=i){
			return 0;
		}
	}
	return 1;
}
void dfs(ll u,ll f,ll sum){
	res=max(res,sum);
	for(auto v:ma[u]){
		if(v==f)continue;
		if(bj[v]){
			dfs(v,u,0);
		}
		else dfs(v,u,sum+1);
	}
}
void dfsn(ll cen,ll sum){
	if(sum>k)return;
	if(cen>n){
		if(check()){
			res=0;dfs(1,0,0);
			ans=min(ans,res);
		}
		return;
	}
	dfsn(cen+1,sum);
	bj[cen]=1;
	dfsn(cen+1,sum+1);
	bj[cen]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			cin>>u>>v;
			lj[u][v]=lj[v][u]=1;
			ma[u].push_back(v);
			ma[v].push_back(u);
		}
		dfsn(1,0);
		cout<<ans<<'\n';
		ans=INT_MAX;
		for(int i=1;i<=n;i++)ma[i].clear();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)lj[i][j]=0;
	}
	return 0;
}

