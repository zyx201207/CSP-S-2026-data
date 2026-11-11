//GZ-S00020 郑淇予 贵阳市第一中学
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;
const int N = 5005, M = 2000005;
ll x[M];
ll dp[N], dist[N];
ll dq[N], sum[N], t = 0, h = 1;
queue<pair<ll, ll> > q[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while(T--){
		//cout << '#' << T << endl;
		
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		FOR(i, 1, n){
			scanf("%lld", &x[i]);
		}
		if(c <= 10 && n <= 5000){//O(n^2)单调队列dp
			//dp[i] = sum{dp[j], x[i]-d <= x[j] <= x[i], dist[j]最小}
			int num = 0;
			FOR(i, 1, n){
				memset(dp, 0, sizeof(dp));
				memset(dist, 0, sizeof(dist));
				dp[i] = 1;
				dist[i] = 0;
				t = 0, h = 1;
				dq[++t] = i;
				q[t] = queue<pair<ll, ll> >();
				sum[t] = dp[i];
				FOR(j, i+1, n){
					while(h <= t && x[dq[h]] < x[j]-d){
						if(q[h].empty())++h;
						else{
							auto nd = q[h].front();
							q[h].pop();
							dq[h] = nd.first;
							sum[h] -= nd.second;
						}
					}
					if(h <= t){
						dp[j] = sum[h];
						dist[j] = dist[dq[h]]+1;
					}
					else{
						break;
					}
					while(h <= t && dist[dq[t]] > dist[j]){
						t--;
					}
					if(h <= t && dist[dq[t]] == dist[j]){
						q[t].push({j, (q[t].empty()?dp[dq[t]]:dp[q[t].back().first])});
						sum[t] += dp[j];
					}
					else{
						dq[++t] = j;
						//cout << j << "%%%" << t << endl;
						sum[t] = dp[j];
						q[t] = queue<pair<ll, ll> >();
					}
					//cout << i << '#' << j << ' ' << dp[j] << '#' << dist[j] << ' ' << h << '#' << t << endl;;
					/*
					FOR(k, h, t){
						cout << dq[k] << '%' << sum[k] << ' ';
					}
					cout << endl;
					*/
					if(dp[j] == 2){
						num++;
					}
				}
			}
			printf("%d\n", num);
		}
		else{//等差数列
			if(n <= 1){
				printf("0\n");
				continue;
			}
			ll x0 = x[1], del = x[2]-x[1];
			if(d < del*2){
				printf("0\n");
				continue;
			}
			ll times = d/del;
			printf("%d\n", max(n-2*times+1, 0ll));
		}
	}
	return 0;
}
