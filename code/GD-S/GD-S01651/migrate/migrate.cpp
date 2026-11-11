#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int csdbh,n,d,t,a[N],dis[N],cnt[N];
queue<int>q;
vector<vector<int> >g;
inline void bfs(int st){
	for(int i=1;i<=n;i++)dis[i]=-1,cnt[i]=0;
	q.push(st);
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
				cnt[v]=1;
			}
			else if(dis[v]==dis[u]+1){
				cnt[v]++;
				q.push(v);
			}
		}
	}
}
inline void sol(void){
	g.clear();
	cin>>n>>d;
	g.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2)res++;
		}
	}
	cout<<res<<'\n'; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>csdbh>>t;
	while(t--)sol();
	return 0;
}
