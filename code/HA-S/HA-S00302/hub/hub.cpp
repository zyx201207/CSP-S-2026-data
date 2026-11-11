#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int C,Tc=1,n,k,dis[N];
bool st[N];
vector<int>e[N];
void add(int a,int b){
	e[a].push_back(b);
}
void solve(int cs){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);add(b,a);
	}
	int res=n+1;
	for(int i=0;i<1<<n;i++){
		queue<int>q;
		for(int j=1;j<=n;j++){
			st[j]=0;
			dis[j]=n+1;
		}
		for(int j=0;j<n;j++){
			if(i>>j&1){
				st[j+1]=1;
				q.push(j+1);
				dis[j+1]=0;
			}
		}
		int x=0,y=0;
		for(int j=1;j<=n;j++){
			if(!st[j])continue;
			x++;
			for(auto k:e[j]){
				if(st[k]&&k>j)y++;
			}
		}
		if(x-y>2||x!=k)continue;
		while(!q.empty()){
			auto t=q.front();
			q.pop();
			for(auto v:e[t]){
				if(dis[v]>dis[t]+1){
					dis[v]=dis[t]+1;
					q.push(v);
				}
			}
		}
		int mx=0;
		for(int j=1;j<=n;j++){
			mx=max(mx,dis[j]);
		}
		res=min(res,mx);
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C;
	cin>>Tc;
	for(int cs=1;cs<=Tc;cs++){
		solve(cs);
	}
	return 0;
}
