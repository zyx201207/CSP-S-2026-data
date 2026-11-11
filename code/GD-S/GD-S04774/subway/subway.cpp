#include<iostream>
#include<vector>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500010],k[510],f[510][510];
struct sd{
	ll v,t;
};
vector<sd>a[600010];
ll in(){
	ll k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)w[i]=in();
	for(ll i=1;i<=n;i++){
		k[i]=in();
		for(ll j=0,v,t;j<k[i];j++){
			v=in();t=in();
			a[v].push_back({m+i,t});
			a[m+i].push_back({v,t});
		}
		for(ll j=1;j<=n;j++)f[i][j]=1e17;
		f[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k[i];j++){
			sd x=a[m+i][j],y;
			ll u=x.v,t=x.t,v;
			for(ll l=0;l<a[u].size();l++){
				y=a[u][l];
				v=y.v;
				f[i][v-m]=min(f[i][v-m],t+y.t);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	ll x,y;
	while(q--){
		cin>>x>>y;
		ll ans=1e17;
		for(ll i=0;i<a[x].size();i++){
			for(ll j=0;j<a[y].size();j++){
				ans=min(ans,a[x][i].t+a[y][j].t+f[a[x][i].v-m][a[y][j].v-m]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
