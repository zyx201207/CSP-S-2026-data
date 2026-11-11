#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 305;
int qwq,n,d,a[N],dis[N],cnt[N],ans;
bool vis[N];
void solve(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	cnt[x] = 1,dis[x] = 0;
	vis[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = 1;i <= n;i++){
			if(abs(a[i] - a[u]) <= d){
				if(dis[u] + 1 < dis[i]){
					dis[i] = dis[u] + 1,cnt[i] = cnt[u];
					if(!vis[i])vis[i] = true,q.push(i);
				}else if(dis[u] + 1 == dis[i]){
					cnt[i] = min(3ll,cnt[u] + cnt[i]);
					if(!vis[i])vis[i] = true,q.push(i);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(cnt[i] == 2)ans++;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef LOCAL
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	cin >> qwq >> qwq;
	while(qwq--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++)cin >> a[i];
		ans = 0;
		for(int i = 1;i <= n;i++)solve(i);
		cout << ans / 2 << endl;
	}
}
