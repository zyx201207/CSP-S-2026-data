#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2000005;
ll T, C, n, dis[N], cnt[N];
ll d, p[N], ans;
void bfs(ll st){
	for(ll i = 1;i <= n;i++){
		dis[i] = 1e8;
		cnt[i] = 0;
	}
	queue<ll> q;
	q.push(st);
	dis[st] = 0;
	while(!q.empty()){
		ll tar = q.front();
		q.pop();
		for(ll i = tar;i <= n && p[i] - p[tar] <= d;i++){
			if(dis[i] > dis[tar] + 1){
				dis[i] = dis[tar] + 1;
				cnt[i] = 0;
				q.push(i);
			}else if(dis[i] == dis[tar] + 1) cnt[i]++;
		}
	}
	for(ll i = st;i <= n;i++)
		if(cnt[i] == 1) ans++;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld" ,&C ,&T);
	if(C >= 13 && C <= 14){
		while(T--){
			scanf("%d%lld" ,&n ,&d);
			ll pos = 0;
			for(ll i = 1;i <= n;i++){
				scanf("%lld" ,&p[i]);
				if(p[i] - p[1] <= d) pos = i;
			}
			printf("%lld\n" ,(pos - 1) * (n - pos));
		}
		return 0;
	}else{
		while(T--){
			scanf("%d%lld" ,&n ,&d);
			for(ll i = 1;i <= n;i++)
				scanf("%lld" ,&p[i]);
			ans = 0;
			for(ll i = 1;i < n;i++) bfs(i);
			printf("%lld\n" ,ans);
		}
		return 0;
	}
	return 0;
}
