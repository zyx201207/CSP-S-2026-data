#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
const int N=501,M=5e5+1;
ll c,n,m,d,q,w[M],dis[N+M];
vector<pii> to[N+M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			to[a].push_back({m+i,t});
			to[m+i].push_back({a,t});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		for(int i=1;i<=n+m;i++) dis[i]=1e18;
		priority_queue<pii,vector<pii>,greater<pii>> q;
		q.push({0,s});
		dis[s]=0;
		while(q.size()){
			pii i=q.top();
			q.pop();
			int d=i.fi,x=i.se;
			if(d>dis[x]) continue;
			for(pii i:to[x]){
				int y=i.fi,z=i.se;
				if(d+z<dis[y]){
					q.push({d+z,y});
					dis[y]=d+z;
				}
			}
		}
		cout<<dis[e]+w[s]+w[e]<<'\n';
	}
	return 0;
}
