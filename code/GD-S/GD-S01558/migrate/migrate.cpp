#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=2e6+5;
ll n,d,x[maxn],res=0;
ll l[maxn],r[maxn];
ll dis[maxn],vis[maxn],cnt[maxn];
struct node{
	ll u,dt;
};
void solve(){
	res=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j>=1;j--){
			if(x[i]-x[j]<=d){
				l[i]=j;
			}else{
				break;
			}
		}
		for(ll j=i;j<=n;j++){
			if(x[j]-x[i]<=d){
				r[i]=j;
			}else{
				break;
			}
		}
//		cout<<l[i]<<' '<<r[i]<<endl;
	}
	for(ll i=1;i<=n;i++){
		queue<node> q;
		memset(vis,0,sizeof vis);
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		dis[i]=0;
		q.push({i,0});
		cnt[i]=1;
		while(!q.empty()){
			ll u=q.front().u,dt=q.front().dt;
//			cout<<u<<' '<<dt<<endl; 
			q.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(ll v=u+1;v<=r[u];v++){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					cnt[v]=cnt[u];
					node x;x.u=v,x.dt=dis[v];
					q.push(x);
				}else if(dis[v]==dis[u]+1){
//					if(v==6)cout<<u<<endl;
					cnt[v]+=cnt[u];
				}
			}
		}
		for(ll j=i+1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<dis[j]<<' '<<cnt[j]<<endl;
			if(cnt[j]==2){
				res++;
			}
		}
	}
	cout<<res<<endl;
}
void solve2(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i];
	if(n==1){
		cout<<0<<endl;
		return;
	}
	ll D=abs(x[2]-x[1]);
	ll w=d/D;
	if(w<=1||n<2*w-1){
		cout<<0<<endl;
	}else{
		cout<<(ll)n-2*w+1<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	if(c==11||c==12)while(t--)solve2();
	else while(t--)solve();
	return 0;
}
