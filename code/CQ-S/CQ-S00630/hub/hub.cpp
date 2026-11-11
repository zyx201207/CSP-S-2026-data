#include<bits/stdc++.h>
using namespace std;
long long Test,T;
long long n,m;
vector<long long> edge[100050];
long long fa[100050];
bool vis[100050];
long long dist[100050];
long long ans;
long long find(long long x){
	if (x == fa[x]){
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(long long x,long long y){
	fa[find(x)] = find(y);
}
bool check(long long x){
	for (long long i = 1;i <= n;i++){
		fa[i] = i;
	}
	for (long long i = 1;i <= n;i++){
		for (auto v:edge[i]){
			if (((x>>(i-1))&1) && ((x>>(v-1))&1)){
				merge(i,v);
			}
		}
	}
	for (long long i = 1;i <= n;i++){
		vis[i] = 0;
	}
	for (long long i = 1;i <= n;i++){
		if ((x>>(i-1))&1){
			vis[find(i)] = 1;
		}
	}
	long long cnt = 0;
	for (long long i = 1;i <= n;i++){
		if (vis[i]){
			cnt++;
		}
	}
	if (cnt > 2){
		return false;
	}
	cnt = 0;
	for (long long i = 1;i <= n;i++){
		if ((x>>(i-1))&1){
			cnt++;
		}
	}
	if (cnt != m){
		return false;
	}
	return true;
}
queue<long long> q;
long long comp(long long x){
	while (!q.empty()){
		q.pop();
	}
	for (long long i = 1;i <= n;i++){
		vis[i] = 0;
		dist[i] = 1e18;
	}
	for (long long i = 1;i <= n;i++){
		if (x>>(i-1)&1){
			vis[i] = 1;
			dist[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()){
		long long u = q.front();q.pop();
		for (auto v:edge[u]){
			if (vis[v]){
				continue;
			}
			vis[v] = 1;
			dist[v] = dist[u]+1;
			q.push(v);
		}
	}
	long long cnt = 0;
	for (long long i = 1;i <= n;i++){
		cnt = max(cnt,dist[i]);
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>Test;
	cin>>T;
	while (T--){
		cin>>n>>m;
		ans = 1e18;
		long long x,y;
		for (long long i = 1;i <= n;i++){
			edge[i].clear();
		}
		for (long long i = 1;i < n;i++){
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for (long long i = 1;i <= n;i++){
			sort(edge[i].begin(),edge[i].end());
		}
		for (long long i = 0;i < (1<<n);i++){
			if (check(i)){
				ans = min(ans,comp(i));
			}
		}
		cout<<ans<<'\n';
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
