#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,d,x[N],dis[N],cnt[N];
bool vis[N];
vector<ll> v[N];
void bfs(ll s){
	queue<ll> q;
	for(int i=1;i<=n;i++){
		vis[i]=0; cnt[i]=0;
		dis[i]=INT_MAX;
	}
	q.push(s);
	vis[s]=1; dis[s]=0; cnt[s]=1;
	while(!q.empty()){
		ll k=q.front();
		q.pop();
		for(auto nx:v[k]){
			if(vis[nx]){
				if(dis[nx]==dis[k]+1&&cnt[nx]!=0){
//					cout << nx << " " << k << " " << dis[k]+1 << "\n";
					cnt[nx]+=cnt[k];
				}
				continue ; 
			}
			dis[nx]=dis[k]+1; cnt[nx]=cnt[k];
//			cout << nx << " " << k << " " << dis[nx] << "\n";
			vis[nx]=1;
			q.push(nx); 
		}
	} 
//	for(int i=1;i<=n;i++){
//		cout << dis[i] << " " << cnt[i] << "\n";
//	}
	return ;
}
void solve(){
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d) break ;
			v[i].push_back(j);
			v[j].push_back(i);
//			cout << i << " " << j << "\n";
		}
	}
//	cout << "\n"; 
//	bfs(5);
	ll ans=0;
	for(int i=1;i<=n;i++){
//		cout << i << "\n";
		bfs(i);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2&&i!=j){
				ans++;
//				cout << i << " " << j << "\n";
			}
		}
	}
	cout << ans/2 << "\n";
	for(int i=1;i<=n;i++) v[i].clear();
}
ll c,T=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4

0 2
5 1
1 3 5 7 9
7 15
1 6 11 16 21 26 31

*/
