#include<bits/stdc++.h>
#define pr pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
const int N=100+1;
int c,T,n,m,k,ans,d[N],h[N],f[N];
pr a[N];
vector<int>e[N],v[2];
queue<int>q;
void pre(int u,bool c){
	q.push(u),f[u]=u;
	while(q.size()){
		int u=q.front(),t;q.pop(),v[c].push_back(u);
		for(int i:e[u])if(i!=k&&f[u]!=(t=a[i].x^a[i].y^u))f[t]=u,q.push(t);
	}
}
void bfs(int u){
	memset(d,0,sizeof d),q.push(u),f[u]=u;
	while(q.size()){
		int u=q.front(),t;q.pop();
		for(int i:e[u])if(i!=k&&f[u]!=(t=a[i].x^a[i].y^u))q.push(t),f[t]=u,d[t]=d[u]+1;
	}
	for(int i=1;i<=n;i++)h[d[i]]++;
}
void sol(){
	v[0].clear(),v[1].clear(),pre(a[k].x,0),pre(a[k].y,1);
	for(int i:v[0])for(int j:v[1]){
		memset(h,0,sizeof h);
		bfs(i),bfs(j),h[0]=0;
		int mx=1,d;while(h[mx])mx++;
		for(d=1;d<mx;d++)if(h[0]<=m)h[0]+=h[d];
		else break;
		ans=min(ans,mx-d);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m,ans=n,m-=2;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++)cin>>a[i].x>>a[i].y,e[a[i].x].push_back(i),e[a[i].y].push_back(i);
		for(k=1;k<n;k++)sol();
		cout<<ans+1<<'\n';
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
