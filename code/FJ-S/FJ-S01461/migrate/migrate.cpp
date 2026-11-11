#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5,inf=1e18;
ll a,b,c,n,m,sum,ans,tot,T,vis[N],len[N],x[N],f[N],d,gc,ffa;
vector<ll> ma[N];
queue<ll> q;
void bfs(ll x){
	for(ll i=1;i<=n;i++)vis[i]=0,len[i]=inf,f[i]=0;
	q.push(x);
	len[x]=0;
	while(!q.empty()){
		ll u=q.front();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:ma[u]){
			if(len[v]==len[u]+1){
				f[v]+=f[u]+1;
			}
			if(len[v]>len[u]+1){
				len[v]=len[u]+1;
				f[v]=f[u];
				q.push(v);
			}
			
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i==2)gc=x[2]-x[1];
			if(i>2&&x[i]-x[i-1]!=gc)ffa=1;
		}
		if(n<=5000){
			ll pos=1;
			for(ll i=1;i<=n;i++){
				while(pos<i&&x[i]-x[pos]>d)pos++;
				for(ll j=pos;j<i;j++){
					ma[i].push_back(j);
					ma[j].push_back(i);
				}
			}
			for(ll i=1;i<=n;i++){
				bfs(i);
				for(ll j=1;j<=n;j++){
					if(j==i)continue;
					if(f[j]==1){
						ans++;
						//cout<<i<<' '<<j<<'\n';
					}
				}
			}
			cout<<ans/2<<'\n';
			ans=0;
			for(int i=1;i<=n;i++)ma[i].clear();
		}
		else if(ffa==0){
			if(d>=3)cout<<0<<'\n';
			else cout<<max(n-3,0ll)<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}