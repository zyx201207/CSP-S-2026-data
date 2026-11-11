#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
int Case, Task;
int n;
ll d;
ll dis[N];
int to[N];
int f[N], pre[N], w[N];
void Clear(){
	memset(dis, 0, sizeof(ll) * (n + 5));
	memset(to, 0, sizeof(int) * (n + 5));
}
void Main(){
	Clear();
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> dis[i];
	for(int i = 1, j = 1; i <= n; i++){
		while(j <= n && dis[j] - dis[i] <= d) j++;
		to[i] = j - 1;
	}
	if(Case <= 10){
		ll sum = 0;
		for(int i = 1; i <= n; i++){
			memset(f, 0, sizeof(int) * (n + 5));
			memset(pre, 0, sizeof(int) * (n + 5));
			memset(w, 0, sizeof(int) * (n + 5));
			f[i] = pre[i] = 1;
			w[i] = 0;
			for(int j = i + 1, k = i, k_ = i; j <= n; j++){
				while(k <= j && dis[j] - dis[k] > d) k++;
				w[j] = w[k] + 1;
				k_ = k;
				while(k_ <= j && w[k_] == w[k]) k_++;
				f[j] = min(3, pre[k_ - 1] - pre[k - 1]);
				pre[j] = pre[j - 1] + f[j];
				if(f[j] == 2) sum++;
			}
		}
		printf("%lld\n", sum);
		return;
	}
	if(Case <= 12){
		int x = d / (dis[2] - dis[1]);
		ll sum = 0;
		for(int i = 1; i <= n; i++){
			if(x == 2) sum += min(2, n - (i + 1));
			else if(x > 2) sum += min(1, n - (i + 1));
 		}
 		printf("%lld\n", sum);
		return;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Case >> Task;
	while(Task--) Main();
	return 0;
} 
/*
0 1
10 19808
18189 32433 51431 63185 69138 79847 88678 93481 105989 126680 
*/
