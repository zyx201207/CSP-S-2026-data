#include<bits/stdc++.h>
using namespace std;

int n , m;
int a[500010];
stack<int> card;
int ans[300010];
int sum[300010];
bool vis[300010];

void solve()
{
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n <= 5000){
		for(int k = 1;k<=n;k++){
			for(int i = k;i<=n;i++){
				if(vis[a[i]] == 0) {
					card.push(a[i]);
					vis[a[i]] = 1;
				} else {
					while(!card.empty() && card.top() != a[i]) {
						int p = card.top();
						vis[p] = 0;
						card.pop();
					}
				}
			}
			while(!card.empty()) {
				ans[card.top()]++;
				vis[card.top()] = 0;
				card.pop();
			}
		}
		for(int i = 1;i<=m;i++){
			cout << ans[i] << " ";
		}
		return;
	}
	
	for(int i = n;i>=1;i--){
		if(vis[a[i]] == 1) {
			while(!card.empty() && card.top() != a[i]) {
				int p = card.top();
				vis[p] = 0;
				ans[p] += sum[p] - i;
				sum[p] = 0;
				card.pop();
			}
		} else {
			vis[a[i]] = 1;
			sum[a[i]] = i;
			card.push(a[i]); 
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] + sum[i] << " ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

