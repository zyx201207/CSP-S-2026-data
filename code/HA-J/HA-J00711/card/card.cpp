#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
stack<int> stk;
int a[N], q[N];
bool vis[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= n; j++){
			if(!vis[a[j]]){
				stk.push(a[j]);
				vis[a[j]] = 1;
			}else{
				for(int k = 1; k <= n; k++){
					if(stk.top() != a[j]){
						vis[stk.top()] = 0;
						stk.pop();
					}else{
						break;
					}
				}
			}
		}
		while(!stk.empty()){
			q[stk.top()]++;
			stk.pop();
		}
	}
	for(int i = 1; i <= m; i++)
		cout << q[i] << ' ';
	return 0;
}
