#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10,Q=1e5+10;
struct node {
	int x,y,id;
}l[Q];
struct O{
	ll v,id;
	O(ll _v,int _id): v(_v), id(_id) {}
	bool operator < (const O &o) const {
		return o.v < v;
	}
};
ll c,n,m,d,q,dis[N],w[N],k[N],a[510][N],t[510][N],wz[N][30],cnt[N],sc[Q];
vector<int> G[N];
bitset<N> p,p2;
bool cmp(node a,node b) {
	return a.x<b.x;
}
inline void solve(int x) {
	p=p2;
	priority_queue<O> q;
	q.push(O(0,x));
	for(int i=1;i<=m;i++)
		dis[i]=1e18;
	dis[x]=0;
	while(!q.empty()) {
		O u=q.top();
		q.pop();
		if(p[u.id])continue;
		p[u.id]=1;
		for(int i=0;i<G[u.id].size();i++) {
			for(int j=1;j<=k[G[u.id][i]];j++) {
				int _i=G[u.id][i];
				int to=a[_i][j];
				if(p[to])continue;
				if(dis[to]>dis[u.id]+t[_i][wz[u.id][i+1]]+t[_i][j]) {
					dis[to]=dis[u.id]+t[_i][wz[u.id][i+1]]+t[_i][j];
					q.push(O(dis[to],to));
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("subway5.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			wz[a[i][j]][++cnt[a[i][j]]]=j;
			G[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>l[i].x>>l[i].y;
		l[i].id=i;
	}
	sort(l+1,l+q+1,cmp);
	for(int i=1;i<=q;i++) {
		if(l[i].x!=l[i-1].x)
			solve(l[i].x);
		sc[l[i].id]=dis[l[i].y]+w[l[i].x]+w[l[i].y];
	}
	for(int i=1;i<=q;i++)
		cout<<sc[i]<<'\n';
	return 0;
}
