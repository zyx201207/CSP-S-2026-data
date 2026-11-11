#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 31;

int c,n,dis[N],t[N]; ll d,a[N];
vector<int> edge[N];
queue<int> q;

void solve(){
	scanf("%d%lld",&n,&d);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]), edge[i].clear();
	for(int i = 1;i <= n;i++){
		int nxt = upper_bound(a + 1,a + n + 1,a[i] + d) - a - 1;
		if(c <= 6){
			for(int j = nxt;j > i;j--)
				edge[i].push_back(j);			
		}else{
			for(int j = nxt;j > nxt - 3;j--)
				if(j > i)
					edge[i].push_back(j);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++)
			t[j] = dis[j] = 0;
		q.push(i); t[i] = 1;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(auto y : edge[x])
				if(dis[y] == 0 || dis[y] == dis[x] + 1){
					if(dis[y] == 0)
						q.push(y);
					dis[y] = dis[x] + 1;
					t[y] += t[x];
				}
		}
		for(int j = i + 1;j <= n;j++)
			if(t[j] == 2)
				ans++;
	}
	printf("%d\n",ans);
}
void solve2(){
	scanf("%d%lld",&n,&d);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	if(d < (a[2] - a[1]) * 2){
		puts("0");
		return;
	}
	a[n + 1] = a[n] + a[2] - a[1];
	int ans = 0;
	for(int i = n;i >= 1;i--){
		t[i] = upper_bound(a + 1,a + n + 2,a[i] + d) - a - 1;
		if(t[t[i] - 1] == t[t[i]] - 1 && t[t[i] - 2] != t[t[i]] - 1)
			ans++;
	}
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t; scanf("%d%d",&c,&t);
	while(t--){
		if(c == 11 || c == 12)
			solve2();
		else
			solve();
	}
}
