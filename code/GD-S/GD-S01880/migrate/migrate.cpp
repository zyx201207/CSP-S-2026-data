#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+100;
const ll inf=1e18;
int c,t,n;
ll x[M];
ll f[M],h[M];
ll d;
bool check(int u,int v){
	for(int i=u;i<=v;i++) f[i]=inf,h[i]=0;
	f[u]=0,h[u]=1;
//	cout<<"CHECK"<<u<<' '<<v<<'\n';
	for(int i=u+1,pos;i<=v;i++){
		pos=max(u,(int)(lower_bound(x+1,x+1+n,x[i]-d)-x));
//		cout<<i<<' '<<pos<<'\n';
		for(int j=pos;j<i && j<=pos+2;j++){
			if(f[i]>f[j]+1) f[i]=f[j]+1,h[i]=h[j];
			else if(f[i]==f[j]+1) h[i]+=h[j];
		}
	}
	if(h[v]==2) return 1;
	return 0;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(check(i,j)) ans++;
	cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

