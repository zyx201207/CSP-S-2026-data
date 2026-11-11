#include<bits/stdc++.h>
using namespace std;
const int N = 2.1e6;
int head[N] , nxt[N << 1] , to[N << 1] , cnt;
inline void add(int x , int y){
	nxt[++cnt] = head[x] , head[x] = cnt , to[cnt] = y;
}
bool vis[N];
int need[N] , mid , tot;
void dfs(int x , int fa){
	for(int i = head[x];i;i = nxt[i]){
		int q = to[i];
		if(q == fa)
			continue;
		dfs(q , x);
		need[x] = max(need[x] , need[q] + 1);
		if(need[x] > mid)
			need[x] = 0 , vis[x] = true;
	}
	return;
}
int n , k;
int ANS[N] , VIS[N];
bool tag[N];
int bfs(int x){
	memset(tag , 0 , sizeof tag);
	queue<pair<int , int> > q;
	q.push({x , 0});
	tag[x] = 1;
	while(!q.empty()){
		pair<int , int> now = q.front();
		q.pop();
		for(int i = head[now.first];i;i = nxt[i]){
			if(VIS[to[i]])
				return now.second + 1;
			else
				if(!tag[to[i]])
					q.push({to[i] , now.second + 1}) , tag[to[i]] = true;;
		}
	}
	return 0;
}
int RES = 20000;
void check(){
	int ans = 0;
	for(int i = 1;i <= n;++ i)
		if(!VIS[i])
			ans = max(bfs(i) , ans);
	RES = min(ans , RES);
}
void DFS(int num){
	if(num == k){
		check();
		return;
	}
	for(int i = 1;i <= n;++ i)
		if(!VIS[i])
			VIS[i] = true , DFS(num+1),VIS[i] =false;
}
int main(){
	freopen("hub.in" , "r" ,stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c , T;
	cin >> c >> T;
	if(c > 3){
		while(T --){
			int a , b;
			cin >> n >> k;
			memset(head , 0 , sizeof head);
			cnt = 0;
			for(int i = 1;i < n;++ i)
				cin >> a >> b , add(a , b) , add(b , a);
			int L = 1 , R = n , ans = 0;
			while(L <= R){
				tot = 0;
				mid = ((L + R) >> 1);
				for(int i = 1;i <= n;++ i)
					vis[i] = false,
					need[i] = 0;
				dfs(1 , 0);
				if(tot + 10 > k)
					L = mid + 1;
				else
					R = mid - 1 , ans = mid;
			}
			cout << mid << '\n';
		}
	}
	else{
		while(T --){
			int a , b;
			cin >> n >> k;
			memset(head , 0 , sizeof head);
			cnt = 0;
			for(int i = 1;i < n;++ i)
				cin >> a >> b , add(a , b) , add(b , a);
			DFS(0);
			cout << RES << '\n';
		}
	}
}