#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=200050;
ll c,t;
ll n,d;
ll dis[N];
inline bool check(ll x){
	return x>=1&&x<=n;
}
void bfs(ll& u,vector<vector<ll>>& v){
	queue<ll> q;
	q.push(u);
	while(!q.empty()){
		ll nw=q.front();
		q.pop();
		for(ll nx:v[nw]){
			if(check(nx)){
				if(!dis[nx])q.push(nx);
				dis[nx]++;
			}
		}
	}
}
void solve(){
	cin >> n >> d;
	if(n<=2){
		cout << 0;
		return;
	}
	ll x[N];
	vector<vector<ll>> v(n+1);
	for(ll i=1;i<=n;i++)cin >> x[i];
	for(ll i=2,j=1;i<=n;i++){
		while(j<i&&x[i]-x[j]>d)j++;
		for(ll k=j;k<i;k++){
			v[x[i]].push_back(x[k]);
			v[x[k]].push_back(x[i]);
		}
	}
	memset(dis,0,sizeof(dis));
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		bfs(i,v);
		for(ll j=1;j<=n;j++){
			if(dis[j]==2)cnt++;
		} 
		memset(dis,0,sizeof(dis));
	}
	cout << cnt << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)solve();
	return 0;
}
