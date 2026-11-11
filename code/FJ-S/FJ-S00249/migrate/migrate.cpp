#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,T,n,d,dis[200010][2],a[2000010],pre[2000010],suf[2000010];
bool bol[200010],bol_[200010];

queue <int> q;

vector <int> edges[200010];

void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	if(n <= 3){
		puts("0");
		return ;
	}
	if(c == 11 || c == 12){
		int num = d / (a[2] - a[1]);
		if(num == 1){
			puts("0");
			return ;
		}
		printf("%lld\n",max(0LL,n - num * 2 + 1));
		return ;
	}
	int l = 1;
	for(int i = 1;i <= n;i++){
		while(l < n && a[i] - a[l] > d){
			l++;
		}
		pre[i] = l;
	}
	l = n;
	for(int i = n;i >= 1;i--){
		while(l > 1 && a[l] - a[i] > d){
			l--;
		}
		suf[i] = l;
	}
	if(c == 13 || c == 14){
		l = 1;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			while(suf[l] <= pre[i]){
				l++;
			}
			if(suf[l] == pre[i] + 1){
				ans++; 
			}
		}
		printf("%lld\n",ans);
		return ;
	}
	for(int i = 1;i <= n;i++){
		edges[i].clear();
		for(int j = i + 1;j <= suf[i];j++){
			edges[i].push_back(j); 
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			bol_[j] = dis[j][0] = dis[j][1] = bol[j] = 0;
		}
		dis[i][0] = 0;
		dis[i][1] = 1;
		while(!q.empty()){
			q.pop();
		}
		q.push(i);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			bol[u] = true;
			for(auto v : edges[u]){
				if(!bol[v]){
					if(dis[v][0] == 0){
						dis[v][0] = dis[u][0] + 1;
						dis[v][1] = dis[u][1];
					}else{
						if(dis[v][0] == dis[u][0] + 1){
							dis[v][1] += dis[v][1];
						}
					}
					if(!bol_[v]){
						bol_[v] = true;
						q.push(v);
					}
				}
			}
		}
		for(int j = i + 1;j <= n;j++){
			if(dis[j][1] == 2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
