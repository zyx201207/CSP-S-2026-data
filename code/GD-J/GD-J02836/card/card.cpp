#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], idx[N], ans[N];
map<int, int> mp; 
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int pos = n - 1, cnt = 1;
		queue<int> q;
		q.push(a[cnt++]);
		while(pos--){
			if(mp[a[cnt]] == 0){
				mp[a[cnt]]++;
				idx[a[cnt]] = cnt;
				q.push(a[cnt++]);
			}
			else{
				int res = cnt - idx[a[cnt]];
				while(res--){
					q.pop();
					pos++;
				}
				q.push(a[cnt++]);
			}
		}
		while(!q.empty()){
			int t;
			t = q.front();
			ans[t]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
