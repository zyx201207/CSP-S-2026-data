//////0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
#include<bits/stdc++.h>

using namespace std; 
typedef long long ll;
const ll N =510;
ll a[N], n, d, c, q,ans;
ll dist[N][N];
bool f[N];
//dist第i,j表示长度为i经过j条路 

void dfs(ll x, ll dep){
	cout<<x<<' '<<dep<<'\n';
	f[x]=1;
	for(ll i=1; i<=n; ++i){
		if(a[i]==x||f[i]) continue;
		
		if(abs(a[x]-a[i])>d) continue;
		if(dist[a[i]][dep]==0||dist[a[i]][dep]>dist[a[x]][dep-1]+abs(a[x]-a[i])){
			dist[a[i]][dep] =dist[a[x]][dep]+abs(a[x]-a[i]);
			//cout<<a[x]<<'a'<<a[i]<<' '<<dep<<'\n';
			dfs(a[i],dep+1);
			f[a[i]]=0;
		}else if(a[i]==a[x]&&dist[a[i]][dep]==dist[a[x]][dep-1]+abs(a[x]-a[i])){
			ans++;
			
			//cout <<a[x] <<'a'<<a[i]<<' '<<dep<<'\n';
			dfs(a[i],dep+1);
			f[a[i]]=0;
		}
	}
	return;
}
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	cin >> c >> q;

	while(q--){
		cin >> n >> d;
		for(ll i=1; i<=n;++i){
			cin>>a[i];
		}
		
		memset(dist,0,sizeof(dist));
		for(ll i=1; i <= n; ++i){
			dist[i][0]=0;
			dfs(i,0); f[i]=0;
		}
		cout<<ans<<'\n';

	}
	
	return 0;

}
