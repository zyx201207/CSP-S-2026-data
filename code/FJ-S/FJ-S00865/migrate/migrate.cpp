#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
ll x[2000025];
ll f[2000025];
ll g[2000025];
ll nxt[2000025];
ll L[2000025];
ll R[2000025];
ll N;
ll c[2000025];
int ins(ll x,ll y){
	while(x<=N){
		c[x]=c[x]+y;
		x+=x&-x;
	}
	return 0;
}
ll gs(ll x){
	ll ans=0;
	while(x){
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll C,t;
	cin>>C>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		bool subA=1;
		R(i,1,n)cin>>x[i];
		R(i,3,n)if(x[i]-x[i-1]!=x[i-1]-x[i-2])subA=0;
		if(subA){
			ll tt=x[2]-x[1];
			ll ts=d/tt;
			if(ts<=1){
				cout<<0<<'\n';
				continue;
			}
			cout<<max(0ll,n-(2*ts-1))<<'\n';
			continue;
		}
		if(n>5001)continue;
		R(i,1,n)nxt[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		ll ans=0;
		E(i,n,1){
			R(j,1,i)g[j]=0;
			R(j,1,i)R[j]=j;
			R(j,1,i)L[j]=j;
			R(j,1,i)c[j]=0;
			N=i;
			f[i]=0;
			g[i]=1;
			ins(i,1);
			E(j,i-1,1){
				f[j]=f[min(i,nxt[j])]+1;
				if(f[j]==f[j+1]){
					R[j]=R[j+1];
					L[R[j]]=j;
				}
				ll tr=min(i,nxt[j]);
				ll tl=max(j+1,L[R[tr]]);
				if(tl<=tr)g[j]=min(3ll,gs(tr)-gs(tl-1));
				ins(j,g[j]);
				if(g[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
//16:52 40pts
//17:04 48pts
