#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+50;
ll head[N],to[N],nxt[N],val[N],cnt;
void add(ll x,ll y,ll z){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	val[cnt]=z;
	head[x]=cnt;
}
ll n,d;
ll x[N],f[N],g[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
void dij(ll s){
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int > p=q.top();
		q.pop();
		for(int i=head[p.second];~i;i=nxt[i]){
			ll j=to[i];
			if(f[j]>f[p.second]+val[i]){
				f[j]=f[p.second]+val[i];
				q.push({f[j],j});
				g[j]=1;
			}
			else if(f[j]==f[p.second]+val[i]){
				g[j]++;
			}
		}
		
	}
}
ll ans;
void solve(){
	ans=0;
	memset(head,-1,sizeof(head));
	memset(val,0,sizeof(val));
	memset(to,0,sizeof(to));
	memset(nxt,0,sizeof(nxt));
	cin>>n>>d;
	ll dd=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i==2){
			dd=x[i]-x[i-1];
		}
		if(i>2){
			if(x[i]-x[i-1]!=dd){
				f=0;
			}
		}
	}
	if(f){
		if(d>=dd){
			if(d%dd==0){
				cout<<n-3<<"\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else{
			cout<<"0\n";
		}
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d){
				add(i,j,abs(x[i]-x[j]));
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=i+3;j<=n;j++){
			if(g[j]==2){
				ans++;
			}
		}
	} 
	cout<<ans<<"\n";
	cnt=0;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
