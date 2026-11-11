#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,T,ans;
int n,d,a[N];
vector<int> g[N];
int f[N],dis[N];
void bfs(int x){
	memset(f,0,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	int dwz=dis[1];
	queue<int> q;
	q.push(x);
	dis[x]=0; 
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(auto v:g[p]){
			if(dis[v]==dwz) q.push(v);
			if(dis[v]==dis[p]+1) f[v]++;
			if(dis[v]>dis[p]+1){
				dis[v]=dis[p]+1;
				f[v]=1;
			}			
		}
	}
	for(int i=1;i<=n;i++) {
		if(f[i]==2){
			ans++;
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) g[i].push_back(j);
		}
	}
	if(a[n]-a[1]<=d){
		cout<<"0\n";
		return ;
	}
	if(c==11||c==12){
		int cha=a[2]-a[1],t=d/cha;
		t=2*t-1;
		if(d<=cha||t>=n){
			cout<<"0\n";
			return ;
		}
		cout<<n-t<<"\n";
		return ;	
	}
	ans=0;
	for(int i=1;i<=n;i++) bfs(i);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--) solve();	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

*/ 
