#include <bits/stdc++.h>
using namespace std;
long long x[2005];
vector<vector<long long> > G(2005);
bool vis[2005];
long long cntpath[2005][2005];
long long Minus(long long a , long long b) {return (max(a , b) - min(a , b));}
bool bfs(long long s , long long t) {
	memset(vis , false , sizeof(vis));
	queue<long long> Q;
	Q.push(s);
	vis[s] = true;
	long long cnt = 0;
	while(!Q.empty()) {
		long long head = Q.front(); Q.pop();
		if(head == t) {
			cnt ++;
		}
		for(auto Next : G[head]) {
			if(!vis[Next]) {
				Q.push(Next);
				vis[Next] = true;
			}
		}
	}
	cout << endl << cnt << endl;
	return (cnt == 2);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	long long c, T;
	cin >> c >> T;
	while(T--) {
		memset(x , 0 , sizeof(x));
		long long n , d;
		cin >> n >> d;
		for(long long i = 1; i <= n; i++) cin >> x[i];
		for(long long i = 1; i <= n; i++) {
			for(long long j = (i + 1); j <= n; j++) {
				//因为|xi-xj|<=d里面i、j是对称的，故可以交换位置；不考虑i=j（因为bfs时不会一直绕着起点转） 
				if(Minus(x[i] , x[j]) <= d) {
					G[i].push_back(j); G[j].push_back(i);
				} 
			}
		}
		long long cnt = 0;
		for(long long i = 1; i <= n; i++) {
			for(long long j = (i + 1); j <= n; j++) {
				if(bfs(i , j)) cnt ++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
