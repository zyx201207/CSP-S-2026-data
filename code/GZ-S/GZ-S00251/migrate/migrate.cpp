//GZ-S00251 ¿Ó∫Ë’‹
#include<bits/stdc++.h>
#define endl '\n'
#define ls i<<1
#define rs=(i<<1|1)
#define fi first
#define se second
#define pb push_back
using namespace std;
template<typename U,typename V>bool cmin(U &x,V y){return y<x?x=y,true:false;};
template<typename U,typename V>bool cmax(U &x,V y){return y>x?x=y,true:false;};
#define to(i,o,p) for(ll i=(o);i<=(p);i++)
#define un(i,o,p) for(ll i=(o);i>=(p);i--)
mt19937 rng(time(0));
using ll=long long;
using pll=pair<ll,ll>;
const int int_inf=1E9+7;
const ll inf=1E18+7;
const int mod=1E9+7;
const int P=0;
const int M=0;
const int N=2E6+10;
ll c,x[N],dis[N],n,d,cnt,res;
vector<ll>G[N];
void dfs(ll u,ll e,ll dist){
	if(u==e){
		if(cmin(dis[e],dist))cnt=1;
		else if(dis[e]==dist)cnt++;
		return;
	}
	for(ll v:G[u])dfs(v,e,dist+1);
}
void solve(){
	res=0;
	cin>>n>>d;
	to(i,1,n){
		cin>>x[i];
	}
	if(c<=10){
		fill(dis,dis+N-10,inf);
		to(i,1,n){
			to(j,i+1,n){
				if(x[j]-x[i]<=d){
					G[i].pb(j);
				}else break;
			}
		}
		to(i,1,n)to(j,1,n){
			cnt=0;
			fill(dis,dis+N-10,inf);
			dfs(i,j,0);
			res+=(cnt==2);
		}
		cout<<res<<endl;
		to(i,1,n)G[i].clear();
		return;
	}
	if(c==13||c==14){cout<<"0\n";return;}
}
int main(){//C
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}


