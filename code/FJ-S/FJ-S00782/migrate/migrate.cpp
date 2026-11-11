#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll f=1,x=0; char ch;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
	return f*x;
}
const ll N=5e3+5;
const ll INF=4e18;
ll _,__;
ll n,d,a[N];
ll dis[N][N];
ll num[N][N];
ll cf(ll x,ll y){
	if(x%y) return x/y+1;
	else return x/y;
}
bool decsl(){
	for(ll i=2;i<n;i++){
		if(a[2]-a[1]!=a[i+1]-a[i]) return false;
	}
	return true;
}

ll ans=0;
void init(){
	ans=0;
	memset(num,0,sizeof(num));
}
int main(){
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	_=read(),__=read();
	while(__--){
		n=read(),d=read();
		for(ll i=1;i<=n;i++) a[i]=read();
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				dis[i][j]=INF;
				for(ll k=i+1;k<j;k++){
					dis[i][j]=min(dis[i][k]+cf((a[j]-a[k]),d),dis[i][j]);
				}
			}
		} 
		for(ll i=1;i<=n;i++);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(num[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
		init();
	}
	return 0;
}

