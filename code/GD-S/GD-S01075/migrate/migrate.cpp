#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n;
ll D,ans=0,x[N],d[N],sum[N];
vector<int> vec[N];
void bfs(int s){
	memset(d,0x3f,sizeof(d));
	queue<int> Q;
	Q.push(s);
	d[s]=0;
	sum[s]=1;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int v:vec[u]){
			if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				sum[v]=sum[u];
				Q.push(v);
			}else if(d[v]==d[u]+1){
				sum[v]+=sum[u];
				if(sum[v]>2||!sum[u]) sum[v]=0;
			}
		}
	}
}
void solve(){
	ans=0;
	cin>>n>>D;
	for(int i=1;i<=n;i++){
		vec[i].clear();
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll dist=abs(x[i]-x[j]);
			if(dist>D) break;
			vec[i].push_back(j);
			vec[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(sum[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
