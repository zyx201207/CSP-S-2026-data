#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define sc second
const int N=2e5+7;
int c,t,n;
ll a[N],d;
vector<ll>vb[N];//a:<-b:->
vector<int>o;
struct Node{
	int pos,dep;
	vector<int>vt;
};
int bfs_b(int x,int ed){
	set<vector<int>>s;
	queue<Node>q;
	q.push({x,0,o});
	int mindep=0;
	while(!q.empty()){
		int pos=q.front().pos,dep=q.front().dep;
		vector<int>vc=q.front().vt;
		q.pop();
		if(mindep && dep>mindep) break;
		if(pos==ed){
			if(mindep==0) mindep=dep;
			s.insert(vc);
			continue;
		}for(int i:vb[pos]) if(pos<=ed){
			vector<int>vi=vc;
			vi.pb(i);
			q.push({i,dep+1,vi});
		}
	}return (int)s.size();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i],vb[i].clear();
		if(c<=10){//O(N^2)
			ll ans=0;
			for(int i=1;i<=n-1;++i) for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d) vb[i].pb(j);
				else break;
			}for(int i=1;i<=n;++i) sort(vb[i].begin(),vb[i].end(),greater<>());
			for(int i=1;i<=n-1;++i) for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d) continue;
				if(bfs_b(i,j)==2) ans++;
			}cout<<ans<<endl;
		}
	}
	return 0;
}/*
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
*/
