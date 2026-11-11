#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq,k[500005],ww[500005],w[500005];
long long a[505][50005],t[505][50005];
long long fa[25][10005];
struct edge{
	int to,nxt,w;
}e[50005];
long long cnt,head[50005];
long long dis[50005];
void add(int u,int v,int w){
	cnt++;
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
struct node{
	long long dis;
	long long  pos;
	bool operator <(const node &x) const{
		return x.dis < dis;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i=1;i <= m;i++){
		cin >> ww[i];
	}
	for(int i=1;i <= n;i++){
		cin >> k[i];
		for(int j=1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			fa[i][a[i][j]] = i;
		}
		for(int j=1;j < k[i];j++){
			add(a[i][j],a[i][j+1],t[i][j]+t[i][j+1]);
			add(a[i][j+1],a[i][j],t[i][j+1]+t[i][j]);
		}
	}
	while(qq--){
		long long x,y;
		cin >> x >> y;
		
		for(int i=1;i <= m;i++){
			dis[i] = 1e18;
		}
		dis[x]=0;
		priority_queue<node> q;
		node cur;
		cur.dis = 0;
		cur.pos = x;
		q.push(cur);
		while(!q.empty()){
			node cum = q.top();
			q.pop();
			long long u = cum.pos;
			long long d = cum.dis;
			if(d > dis[u]){
				continue;
			}
			for(int l=head[u];l;l=e[l].nxt){
				int v = e[l].to;
				if(dis[v] > dis[u] + e[l].w){
					dis[v] = dis[u] + e[l].w;
					node cut;
					cut.dis = dis[v];
					cut.pos = v;
					q.push(cut);
				}
			}
		}
		cout<<dis[y]+ww[x]+ww[y] <<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3 
//1 2
