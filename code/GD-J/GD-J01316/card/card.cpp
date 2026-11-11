#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500005;
const int maxm = 300005;
int n , m;
stack<int> stk;
bool vis[maxm];
int a[maxn];
int ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		//memset(vis, 0, sizeof(vis));
		while(!stk.empty()) stk.pop();
		for(int j = i; j <= n; j++){
			if(vis[a[j]]){
				while(!stk.empty()){
					if(stk.top() != a[j]) {
						vis[stk.top()] = 0;
						stk.pop();
					}
					else break;
				}
				stk.pop();
			}
			stk.push(a[j]);
			vis[a[j]] = 1;
		}
		while(!stk.empty()){
			if(vis[stk.top()]) ans[stk.top()]++;
			vis[stk.top()] = 0;
//			cout << stk.top() << " ";
			stk.pop();
		}
//		cout << "\n";
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
