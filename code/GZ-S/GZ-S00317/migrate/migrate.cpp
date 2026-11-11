//GZ-S00317
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define eb emplace_back
random_device rnd;
mt19937 rd(rnd());
const ll N=2e6+9,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,d,dis[N],f[N],q[N],hd,tl,ans,a[N];
vector<ll> G[N];
inline void bfs(ll st){
	for(int i=st;i<=n;i++) dis[i]=INF,f[i]=0;
	dis[st]=0;
	f[st]=1;
	hd=1,tl=0;
	q[++tl]=st;
	while(hd<=tl){
		ll ls=q[hd++];
		for(auto j:G[ls]){
			if(dis[j]>dis[ls]+1){
				dis[j]=dis[ls]+1;
				f[j]=f[ls];
				q[++tl]=j;
			}
			else if(dis[j]==dis[ls]+1){
				f[j]+=f[ls];
				f[j]=min(f[j],3LL);
			}
		}
	}
	for(int i=st;i<=n;i++){
//		cout<<st<<" "<<i<<" "<<f[i]<<"\n";
		if(f[i]==2) ans++;
	}	
}
inline void solveS(){
	ans=0;
	for(int i=1;i<=n;i++) G[i].clear();
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll r=0;
	for(int i=1;i<=n;i++){
		while(r+1<=n&&abs(a[r+1]-a[i])<=d) r++;
		for(int j=i+1;j<=r;j++){
			G[i].eb(j);
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	cout<<ans<<"\n";
}
inline void solveA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<"\n";
		return ;
	}
	ll del=a[2]-a[1];
	if(d<del){
		cout<<0<<"\n";
		return ;
	}
	ll k=d/del;
	if(k==1){
		cout<<0<<"\n";
		return ;
	}
	cout<<max(0LL,n-2*k+1)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	cin>>c>>T;
	if(c>=11&&c<=12){
		while(T--) solveA();
	}
	else{
		while(T--) solveS();
	}
	return 0;
}

