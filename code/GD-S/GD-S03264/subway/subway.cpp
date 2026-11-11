#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e7+10,N=5e5+10;
int c,n,d,m,q,w[N],k,cnt[N],v,s,t,vis[N],dis[N],a;
vector<pair<int,int>> e[M];
struct node{
	int idx,len;
	bool operator <(const node &z)const{
		return len>z.len;
	}
};
void dj(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(q.size()){
		node o=q.top();
		q.pop();
		ll fr=o.idx;
		if(vis[fr]) continue;
		vis[fr]=1;
		for(auto p:e[fr]){
			ll to=p.first;
			ll len=p.second;
			if(dis[to]>=dis[fr]+len){
				dis[to]=dis[fr]+len;
				q.push({to,dis[to]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	//	e[i].push_back({i+m,w});
	//	e[i+m].push_back({i,w});
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		ll b=0;
		for(int j=1;j<=k;j++){
			cin>>a;
			cnt[a]++;
			if(b) {
			//	cout<<b<<" "<<cnt[a]*m+a<<endl;
				e[b].push_back({cnt[a]*m+a,ll(0)});
				e[cnt[a]*m+a].push_back({b,ll(0)});
			}
			b=cnt[a]*m+a;
			cin>>v;
			e[a].push_back({cnt[a]*m+a,v});
			e[cnt[a]*m+a].push_back({a,v});
		}
	}
//	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		dj();
		cout<<w[s]+dis[t]+w[t]<<endl;
	}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

	return 0;
}

