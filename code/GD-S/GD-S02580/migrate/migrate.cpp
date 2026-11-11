#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v[5005];
int a[5005];
int dis[5005];
int cnt[5005];
int n,m;
void init(){
	for(int i = 1;i <= n;i++){
		v[i].clear();
		a[i] = cnt[i] = 0;
		dis[i] = 0x3f3f3f3f3f;
	}
}
int minn = INT_MAX,ans = 0;
void run(int x,int tar,int cnt){
	if(x == tar){
		if(minn == cnt) ans++;
		else if(minn > cnt) ans = 1,minn = cnt; 
	}
	for(int j = x + 1;j <= tar;j++){
		if(a[j] - a[x] <= m) run(j,tar,cnt+1);
	}
}
void bfs(int x){
	queue<int> q;
	dis[x] = 0;
	cnt[x] = 1;
	q.push(x);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto k : v[x]){
			if(dis[x] + 1 > dis[k]) continue;
			if(dis[x] + 1 == dis[k]){
				dis[k] = dis[x] + 1;
				cnt[k] += cnt[x];
			}
			else{
				dis[k] = dis[x] + 1;
				cnt[k] = cnt[x];
				q.push(k); 
			}
		}
	}
}
void work(){
	cin >> n >> m;
	init();
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 10){
		int sum = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				run(i,j,0);
				if(ans == 2) sum++;
				ans = 0,minn = INT_MAX; 
			}
		}
		cout << sum;
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[j] - a[i] <= m){
					v[j].push_back(i);
					v[i].push_back(j); 
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			bfs(i);
			for(int j = i + 1;j <= n;j++){
				if(cnt[j] == 2) ans++;
			}
			for(int j = 1;j <= n;j++){
				cnt[j] = 0;
				dis[j] = 0x3f3f3f3f3f;
			}
		}
		cout << ans;
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		work();
		cout << endl;
	}
}
