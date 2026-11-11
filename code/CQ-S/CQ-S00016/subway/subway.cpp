#include<bits/stdc++.h>
using namespace std;
#define LG long long
const int INF = INT_MAX / 2;
const int MAXN = 500010;
int n,m,TEST,df,q,wst[510],op,head[510],cnt,d[MAXN],xl[510][510],p[MAXN],px,FLAGA = 1,FLAGB = 1;
struct node{
	int next;
	int to,id;
}G[MAXN * 2];
void add(int u,int v,int id){
	G[++cnt].to = v;
	G[cnt].id = id;
	G[cnt].next = head[u];
	head[u] = cnt;
}
priority_queue<pair<int,int> >pq;
void dij(int u){
	int past = -1;
	for(int i = 1; i <= n; i++) d[i] = INF;
	pq.push(make_pair(0,u));
	d[u] = wst[u];
	while(!pq.empty()){
		int k = pq.top().second;
		pq.pop();
		for(int i = head[k]; i; i = G[i].next){
			int j = G[i].to,sum = 0;
			if(past != -1 && past != G[i].id){
				sum = xl[past][k] + xl[G[i].id][k];
			}
			else if(past == -1) sum = xl[G[i].id][k];
			if(d[j] > d[k] + sum){
				d[j] = d[k] + sum;
				p[j] = G[i].id;
				past = G[i].id;
				pq.push(make_pair(-d[j],j));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int w,last,s,t;
	cin >> TEST >> m >> n >> df >> q;
	for(int i = 1; i <= n; i++){
		cin >> wst[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> op;
		last = -1;
		for(int j = 1; j <= op; j++){
			cin >> w >> t;
			xl[i][w] = t;
			if(last != -1){
				add(last,w,i);
				add(w,last,i);
			}
			last = w;
		}
	}
	while(q--){
		cin >> s >> t;
		dij(s);
		cout << d[t] + wst[t] + xl[p[t]][t] << endl;
	}
	return 0;
}
