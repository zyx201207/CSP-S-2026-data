#include<bits/stdc++.h>
using namespace std;
//关注luogu 1406766 谢谢喵 
typedef  long long ll;
const ll N=5005,INF=0x3f3f3f3f3f3f3f3f,M=2e6+5; 
ll c,T,f[N][N],n,d,a[M],ans;
vector<ll> v[N];
ll dis[N],vis[N];
struct node{
	ll x,y;
	bool operator<(const node &t)const{
		return t.y<y;
	}
};
priority_queue<node> q;
void dij(ll s){
	for(ll i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;
	q.push(node{s,0});
	f[s][s]=1;
	while(q.size()){
		ll t=q.top().x;
		q.pop();
		if(vis[t])continue;
		vis[t]=1;
		for(ll i:v[t]){
			if(dis[i]>=dis[t]+1ll){
				if(dis[i]==dis[t]+1ll)f[s][i]+=f[s][t];
				else dis[i]=dis[t]+1ll,f[s][i]=1ll;
				q.push(node{i,dis[i]});
			}
		}
	}
}
void solve1(){
	cin>>n>>d;
	ans=0;
	memset(f,0,sizeof(f));
	for(ll i=1;i<=n;i++){
		v[i].clear();
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)v[i].push_back(j); 
		}
	}
	for(ll i=1;i<=n;i++){
		dij(i);
		for(ll j=1;j<=n;j++){
			//cout<<dis[j]<<" ";
			if(f[i][j]==2)ans++;
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;
	ll t;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	t=a[2]-a[1];
	if(t==0){
		cout<<0<<"\n";
		return ;
	}
	ll k=d/t;
	if(k<2)cout<<0<<"\n";
	else{
		for(int i=1;i<=n;i++){
			ll l=max(1ll,i-2*k+1),r=max(1ll,i-k-1);
			ans=ans+(r-l+1);	
		}
		cout<<ans<<"\n";
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c<=10)solve1();
		else if(c==11||c==12)solve2();
	}
	return 0;
}
/*
1-6可以n^3暴力 - 24pts
7-10 需要n^2  


*/

