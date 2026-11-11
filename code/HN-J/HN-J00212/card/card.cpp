#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 3e5 + 5;
int n, m, a[N], last[N], f[M], ans[N], maxx;
bool flag[N];
queue<int> q;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(f[a[i]] == 0){
			f[a[i]] = i;
			last[i] = -1;
		}else{
			last[i] = f[a[i]];
			f[a[i]] = i;
		}
	}
	int was = 0;
	for(int i = 1; i <= n; i++){
		was = 0;
		while(q.size()) q.pop();
		for(int j = i; j <= n; j++){
			if(last[j] != -1 && last[j] >= i && last[j] > was){
				while(q.size()){
					was++;
					q.pop();
				}
				q.push(a[j]);
			}else q.push(a[j]);
		}
		while(q.size()){
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= maxx; i++) cout << ans[i]<<' ';
	return 0;
} 
