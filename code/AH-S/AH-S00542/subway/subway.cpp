#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
struct node{
	long long id, pos;
}s[N][N];
long long t[N][N];
long long c, n, m, d, q, a[N], g, h, minn = 10000000;
void dfs(long long x, long long dmp, long long p){
	if(x == h){
		minn = min(minn, dmp + a[x] + t[x][p]);
		return;
	}
	for(int i = 1; i <= s[x][0].id; i ++){
		if(p == s[x][i].pos){
			dfs(s[x][i].id, dmp, p);
		}else{
			dfs(s[x][i].id, dmp + t[x][s[x][i].pos] + t[x][p], s[x][i].pos);
		}
	}
}
int main(){
	freopen("subway.in","r", stdin);
	freopen("subway.out","w", stdout);
	cin>> c>> n>> m>> d>> q;
	for(int i = 1; i <= m; i ++){
		cin>> a[i];
	}
	for(int i = 1; i <= n; i ++){
		long long k;
		cin>> k;
		long long lastid = 0;
		for(int j = 1; j <= k; j ++){
			long long u, v;
			cin>> v>> u;
			s[lastid][0].id ++;
			s[lastid][s[lastid][0].id].id = v;
			s[lastid][s[lastid][0].id].pos = i;
			lastid = v;
			t[v][i] = u;
		}
	}
	while(q --){
		cin>> g>> h;
		minn = 100000000;
		dfs(g, a[g], 0);
		cout<< minn<< "\n";
	}
	return 0;
} 
