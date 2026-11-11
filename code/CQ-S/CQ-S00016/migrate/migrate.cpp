#include<bits/stdc++.h>
using namespace std;
#define LG long long
const int INF = INT_MAX / 2;
const int MAXN = 200010;
int m,n,head[MAXN],cnt,d[MAXN],c,t,a[MAXN],cnts,ans,tt;
struct node{
	int next;
	int to,w;
}G[MAXN];
void add(int u,int v,int w){
	G[++cnt].w = w;
	G[cnt].to = v;
	G[cnt].next = head[u];
	head[u] = cnt;
}
priority_queue<pair<int,int> >q;
void dij(int u){
	cnts = 0;
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[u] = 0;
	q.push(make_pair(0,u));
	while(!q.empty()){
		int k = q.top().second;
		q.pop();
		for(int i = head[k]; i; i = G[i].next){
			int j = G[i].to;
			if(d[j] > d[k] + G[i].w && d[k] + G[i].w <= m){
				d[j] = d[k] + G[i].w;
				cnts = 0;
				q.push(make_pair(-d[j],j));
			}
			else if(d[j] == d[k] + G[i].w && j == tt) cnts++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cnt = ans = 0;
		memset(head,0,sizeof(head));
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			for(int j = 1; j < i; j++){
				add(j,i,a[i] - a[j]);
			}
		}
		dij(1);
		for(int i = 2; i <= n; i++){
			tt = i;
			if(cnts == 1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
