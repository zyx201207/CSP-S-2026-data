#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, m;
int a[N];
int g[N];
queue<int>q;
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int p = 1;
	int pos = 1;
	for(int i = 1; i <= n; i++){
		memset(cnt,0,sizeof cnt);
		for(int j = p; j <= n; j++){
			q.push(a[j]);
			cnt[a[j]]++;
			if(cnt[a[j]] > 1){
				int op = 0;
				while(op != 2){
					int u = q.front();
					q.pop();cnt[a[j]]--;
					if(u == a[j]){
						op++;
					}
				}
			}
		}
		while(q.size() > 1){
			int u = q.front();
			q.pop();
			g[u]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << g[i] << " ";
	}
	return 0;
}
