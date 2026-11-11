#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+86;
const int F=1911;
ll c,n,m,d,q,k;
struct T{
	ll stages,val;
}; 
T b[F][F];
ll a[N],kk[N],ss[N],ee[N];
ll ljy[F][F];
bool f=0;
void fc(){
	memset(ljy,0,sizeof(ljy));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=kk[i];j++){
			for(int k=1;k<=j;k++){
				ljy[k][j]=ljy[j][k]=1;
			}
		}
	}
	
}
ll lf[N];
vector<ll>be[N];
ll ans;
void dfs(ll u,ll v,ll times,ll step){
	if(step==v){
		ans=min(ans,times);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=step){
			for(int j=0;j<be[i].size();j++){
				for(int k=1;k<=kk[be[i][j]];k++){
					if(b[be[i][j]][k].stages!=i&&!lf[b[be[i][j]][k].stages]){
						lf[b[be[i][j]][k].stages]=1;
						dfs(u,v,times+b[be[i][j]][step].val+b[be[i][j]][b[be[i][j]][k].stages].val,b[be[i][j]][k].stages);
						lf[b[be[i][j]][k].stages]=1;
					}
				} 
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&kk[i]);
		if(kk[i]>2) f=1;
		for(int j=1;j<=kk[i];j++){
			scanf("%lld%lld",&b[i][j].stages,&b[i][j].val);
			be[b[i][j].stages].push_back(i);
		}
	}
	if(!f){
		for(int i=1;i<=q;i++){
			scanf("%lld%lld",&ss[i],&ee[i]);
			ans=INT_MAX;
			lf[ss[i]]=1;
			dfs(ss[i],ee[i],a[ss[i]]+a[ee[i]],ss[i]);
			lf[ss[i]]=0;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&ss[i],&ee[i]);
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",a[ss[i]]+a[ee[i]]);
	}
	return 0;
}

