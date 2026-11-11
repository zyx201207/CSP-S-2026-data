#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,d;
int n,a[2000005];
int dis[5005],g[5005];
vector<int> v[5005];
struct o{
	int x;
};
queue<int> q;
void bfs(int st){
	for(int i=st;i<=n;i++){
		dis[i]=1e18;
		g[i]=0;
	}dis[st]=0;
	q.push(st);
	g[st]=1;
//	cout<<dis[6]<<endl;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		if(st==1) cout<<u<<" "<<dis[u]<<" "<<g[u]<<endl; 
		for(auto y : v[u]){
//			if(y==6&&st==1) cout<<y<<" "<<dis[y]<<" "<<u<<endl;
			if(dis[y]>dis[u]+1){
				dis[y]=dis[u]+1;
				g[y]=g[u];
				q.push(y);
			}else if(dis[y]==dis[u]+1){
				g[y]+=g[u];
			}
		}//if(st==1) cout<<dis[6]<<" "<<u<<endl;
	}
}
void work1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		v[i].clear();
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			v[i].push_back(j);
//			cout<<i<<" "<<j<<endl;
		}
	}for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(g[j]==2) ans++;
		}
	}cout<<ans<<endl;
}void work2(){
	int u=a[2]-a[1];
	if(u>d){
		cout<<0<<endl;
		return;
	}u=d/u;
	if(u==1){
		cout<<0<<endl;
		return ;
	}u=u*2;
	cout<<max(0ll,n-u+1)<<endl;
	return;
}
void work3(){
	int u=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
			u=i;
			break;
		}
	}
	if(u>=n-1){
		cout<<0;
		return;
	}int ans=0;
	int k;
	for(int i=n;i;i--){
		if(a[i]-a[u-1]<=d) break;
		k=i; 
	}
	for(int i=1;i<u;i++){
		if(a[u+1]-a[i]>d) continue;
		if(a[u+2]-a[i]<=d) continue;
		ans+=n-k+1;
	}cout<<ans<<endl;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c<=10) work1();
	else if(c==11||c==12) work2();
	else if(c==13||c==14){
		work3();
	}else cout<<0<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
