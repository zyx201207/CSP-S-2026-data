#include<bits/stdc++.h>
#define ll long long
#define enter putchar('\n');
#define space putchar(' ');
using namespace std;
const ll N=2e6+5;
ll read();
void write(ll x);
ll n,d,x[N],ans,vis[N],st[N];
void bfs(ll s){
	queue<pair<ll,ll>> q;
	for(int i=1;i<=n;i++){
		st[i]=0ll;
		vis[i]=0ll;
	}
	q.push({s,0ll});
	while(!q.empty()){
		ll u=q.front().first;
		ll t=q.front().second;
		q.pop();
		if(vis[u]>=1){
			if(t==st[u]){
				vis[u]++;
				for(ll i=u+1;i<=n;i++){
			        if(x[i]-x[u]<=d){
				        q.push({i,t+1});
			        }
			        else break;
		        }
			}
			continue;
		}
		vis[u]=1;
		st[u]=t;
		for(ll i=u+1;i<=n;i++){
			if(x[i]-x[u]<=d){
				q.push({i,t+1});
			}
			else break;
		}
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==2ll) ans++;
	}
}
void solve(){
	n=read();
	d=read();
	ans=0;
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	write(ans);
	enter;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ll c,T;
    c=read();
    T=read();
    while(T--) solve();
	return 0;
}
ll read(){
	ll op=1,cnt=0;
	int c;
	c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-') op*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return op*cnt;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
